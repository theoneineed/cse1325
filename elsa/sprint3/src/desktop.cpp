#include "desktop.h"

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


Desktop::Desktop (std::istream& ist)
{
  int loop_size;
  ist>>loop_size;
  //My thought process behind this is same as when prof. showed us for hexdump where first three characters were read to find the file extension
  for(int i=0;i<loop_size;i++)
  {
    ist>>options[i];
  };
}


void Desktop::save (std::ostream& ost)
{
  int loop_size= options.size();
  ost<<loop_size<<std::endl;
  for(int i=0;i<loop_size;i++)
  {
    ost<<options[i];
  };
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop) {
    ost << "Desktop includes";
    for(auto o : desktop.options) ost << "\n  " << *o;
    return ost;
}
