#ifndef __COLOR_H
#define __COLOR_H

#include <iostream>
#include <string>
#include <sstream> //got it from geeksforgeeks
class Color
{
private:
  int _red,_green,_blue;
public:
  Color(int red, int green, int blue);
  //Since all the colors will be combination of rgb
  std::string to_string();
  //method returns a string representation of the RGB
  std::string colorize(std::string text);
  //method returns its parameter preceded by the ANSI escape code for set fg color,and followed by ANSI esc code for Reset
  int magnitude();//0.21 red, 0.72 green,0.07blue
  int compare(const Color& rhs)
  ;
};







#endif
