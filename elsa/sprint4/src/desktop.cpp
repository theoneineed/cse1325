#include "desktop.h"
#include <iostream>
Desktop::Desktop()
{
  std::vector<Options*> options;
};

void Desktop::add_option(Options& option)
{
  options.push_back(&option);
}

double Desktop::price()
{
    double p = 0.0;
    for(auto o : options) p+= o->cost();
    return p;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop) {
    ost << "Desktop includes";
    for(auto o : desktop.options) ost << "\n  " << *o;
    return ost;
}

Desktop::Desktop (std::istream& ist)
{
  int loop_size;
  ist>>loop_size;
  //My thought process behind this is same as when prof. showed us for hexdump where first three characters were read to find the file extension
  for(int i=0;i<loop_size;i++)
  {
    options.push_back(new Options {ist});
  };
}


void Desktop::save (std::ostream& ost)
{
  int loop_size= options.size();
  ost<<loop_size<<std::endl;
  for(int i=0;i<loop_size;i++)
  {
    options[i]->save(ost);
  };
}
