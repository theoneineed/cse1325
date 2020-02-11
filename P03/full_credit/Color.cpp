#include "Color.h"

Color::Color (){};
Color::Color (int red, int green, int blue):_red{red},_green{green},_blue{blue}{}

std::string Color::to_string()
{
  std::string data= "(" +std::to_string(_red)+","+std::to_string(_green)+","+std::to_string(_blue)+")";
  return data;
}
/*
std::string Color::colorize(std::string text)
{
  std::stringstream g;

  g<<"\033[38;2;"
  <<_red<<";"
  <<_green<<";"
  <<_blue
  <<"m"//I am using prof's notes as reference here
  <<text//Text to print in the color
  <<"\033[0m"; //Resets terminal to default state
  //<<std::endl;  //Newline and flushes the output buffer
*/

std::ostream& operator<< (std::ostream& ost, const Color& color)
{
  ost
  << "\033[38;2;"
  <<color._red
  <<";"
  <<color._green
  <<";"
  <<color._blue
  <<"m";
  return ost;
}

std::istream& operator>>(std::istream& ist, Color& color)
{
  std:: string red1,green1,blue1;
  std::string whole;
  ist>>whole;
  int pos=whole.find(",");
  red1= whole.substr(1,pos-1);

  //std::cout<<whole<<std::endl;
  //std::cout<<red1<<std::endl;
/*
std::string s;
get(ist,s,',');
std::cout<< s;
*/
  whole=whole.substr(pos+1);
  pos=whole.find(",");
  green1= whole.substr(0,pos);



  //std::cout<<green1<<std::endl;
  //std::cout<<whole<<std::endl;




  whole=whole.substr(pos+1);
  pos=whole.find(")");
  blue1= whole.substr(0,pos);
  //std::cout<<whole<<std::endl;



  whole= whole.substr(pos);
  //std::cout<<blue1<<std::endl;
  //std::cout<<whole<<std::endl;

//  std::cout<<red1<<green1<<blue1<<std::endl;

  //ist>>red1>>green1>>blue1;
  color._red=std::stoi(red1);//stoi is used to convert string to integer
  color._green=std::stoi(green1);//stoi is used to convert string to integer
  color._blue=std::stoi(blue1);//stoi is used to convert string to integer
  //ist>>red1>>green1>>blue1;//that way, we can get the value

  return ist;
}
