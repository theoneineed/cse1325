#include "Color.h"

Color::Color (int red, int green, int blue):_red{red},_green{green},_blue{blue}{}

std::string Color::to_string()
{
  std::string data= "(" +std::to_string(_red)+","+std::to_string(_green)+","+std::to_string(_blue)+")";
  return data;
}

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

  return g.str();
}

int Color::magnitude()//0.21 red, 0.72 green,0.07blue
{
  int dvalue= 0.21*_red+0.71*_green+0.07*_blue;
  return dvalue;
}
