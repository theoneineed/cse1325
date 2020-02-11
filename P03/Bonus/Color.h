#ifndef __COLOR_H
#define __COLOR_H

#include <iostream>
#include <string>
#include <sstream> //got it from geeksforgeeks
#include <string.h>
#include <cstring>

class Color
{
private:
  int _red,_green,_blue;
  bool _reset;
public:
  Color();//it is given in the diagram, default constructor
  Color(int red, int green, int blue);
  //Since all the colors will be combination of rgb
  std::string to_string();
  //method returns a string representation of the RGB
  //std::string colorize(std::string text);
  friend std::ostream& operator<< (std::ostream& ost, const Color& color);
  //from the slides of prof
  friend std::istream& operator>>(std::istream& ist, Color& color);
  //friend, because another one needs access to this
  int magnitude ();
  int compare(Color rhs);

};







#endif
