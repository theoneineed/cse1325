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

  std::cout<<Rose<<"Let's hope "<< Bird<<"this thing "<< Bet<<"works.\n"<<std::endl
  <<"\033[0m"
  <<std::endl;

  Color syal;
  std::cout<<"Enter color as (red, green, blue): "<<std::endl;
  std::cin>>syal;
  std::cout << syal << syal.to_string()<<std::endl;
  
//  std::cin>>red>>green>>blue;
//  Color color (red, green, blue);
//  std::cout<<<<std::endl

  /*
  std::cout << "Enter red, green, and blue ints:";
  std::cin>>red>>green>>blue;
  Color color {red, green, blue};
  text= color.to_string();

  std::cout<<color.colorize(color.to_string())<<std::endl;
  */

}
