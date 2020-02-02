#include <iostream>
using namespace std;
class Color
{
public:
  Color(int red, int green, int blue);
  //Since all the colors will be combination of rgb
  std::string to_string();
  //method returns a string representation of the RGB
  std::string colorize(std::string text);
  //method returns its parameter preceded by the ANSI escape code for set fg color,and followed by ANSI esc code for Reset
};

int main()
{
  //instances color class into 3 objects
  //then, ask thhe user for 3 integers representing r,g,b.print the integers in color that comes from the comb. of the given no
  

}
