#include "ram.h"
#include <iostream>
#include <string>
#include <cstring>
#include <ostream>
  Ram::Ram(std::string name, double const, int gb)
  {  }

  Ram:: ~Ram(){}

  Ram::Ram(std::istream& ist)::Options(ist)
  {
    getline(ist,_name);
    ist>>_cost;
    ist.tgnore();
  }

std::string to_string(int n)
{
  switch(n)
  {
    case 1: return "1 GB";
    case 2: return "2 GB";
    case 3: return "3 GB";
    case 4: return "4 GB";
    case 5: return "5 GB";
    case 6: return "6 GB";
    default: return "Default Ram size";
  }
}

std::ostream& operator<<(std::ostream& ost) {
    ost << Ram.size();
    return ost;
}


std::string Ram::gb1()
{
  return std::to_string(_gb);
}
