#include "Color.h"
Color::Color (){};
Color::Color (int red, int green, int blue):_red{red},_green{green},_blue{blue}{}

std::string Color::to_string()
{
  std::string data= "(" +std::to_string(_red)+","+std::to_string(_green)+","+std::to_string(_blue)+")";
  return data;
}



int Color::magnitude() const {
  return static_cast<int> //got help from prof's slides
  (
    0.21 * (int)_red
    + 0.72 * (int)_green
    + 0.07 * (int)_blue
  );
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
  if (color._reset==true)
  {
    ost<<"\033[0m";
  }
  else
  {
      ost
      << "\033[38;2;"
      <<color._red
      <<";"
      <<color._green
      <<";"
      <<color._blue
      <<"m";
  }
  return ost;
}

std::istream& operator>>(std::istream& ist, Color& color)
{
  std:: string red1,green1,blue1;
  std::string whole;
  ist>>red1>>green1>>blue1;

  color._red=std::stoi(red1);//stoi is used to convert string to integer
  color._green=std::stoi(green1);//stoi is used to convert string to integer
  color._blue=std::stoi(blue1);//stoi is used to convert string to integer
  return ist;//that way, we can get the value
}

bool operator <(int rhs )
{
  if (magnitude()<rhs)
  {
    std::cout
    <<"\033[38;2;"
    <<whole
    <<" is greater than "
    <<rhs
    <<"\033[0m";

    return true;

  }
}

bool operator >(int rhs )
{
  if (magnitude()>rhs)
  {
    std::cout
    <<"\033[38;2;"
    <<whole
    <<" is less than "
    <<rhs
    <<"\033[0m";


    return true;
  }
}



bool operator <=(int rhs )
{
  if (magnitude()<rhs || magnitude()==rhs)
  {
    std::cout
    <<"\033[38;2;"
    <<whole
    <<" is greater than or equal to"
    <<rhs
    <<"\033[0m";


    return true;

  }
}

bool operator >=(int rhs )
{
  if (magnitude()>rhs || magnitude()==rhs())
  {
    std::cout
    <<"\033[38;2;"
    <<whole
    <<" is lesser than or equal to "
    <<rhs
    <<"\033[0m";


    return true;

  }
}



bool operator ==(int rhs )
{
  if (magnitude()==rhs)
  {
    std::cout
    <<"\033[38;2;"
    <<whole
    <<" is equal to "
    <<rhs
    <<"\033[0m";

    return true;
  }
}


bool operator !=(int rhs )
{
  if (magnitude()!=rhs)
  {
    std::cout
    <<"\033[38;2;"
    <<whole
    <<" is not equal to "
    <<rhs
    <<"\033[0m";

    return true;
  }
}
