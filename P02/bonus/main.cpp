#include <iostream>
#include <string>
#include "Color.h"

int main()
{

  int red,green,blue;
  std::string text;

  Color Rose{255,0,0};
  Color Bird{0,255,85};
  Color Bet{0,25,185};

  std::cout<<Rose.colorize("UTA Campus "+std::to_string(Rose.magnitude()))<< Bird.colorize(" This is green "+std::to_string(Bird.magnitude()))<< Bet.colorize(" This is not green."+std::to_string(Bet.magnitude()))<<std::endl;


  std::cout << "Enter red, green, and blue ints:";
  std::cin>>red>>green>>blue;
  Color color {red, green, blue};
  text= color.to_string();

  std::cout<<color.colorize(color.to_string()+std::to_string( 0.21*red+0.71*green+0.07*blue))<<std::endl;
}
