#include "desktop.h"

Desktop::Desktop(){};

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
  int n=std::stoi(getline(ist));
  int loop_size= n;
  for(int i=0;i<loop_size;i++;)
  {
    ist>>options[i];
  };
}


void Desktop::save (std::ostream& ost)
{
  int loop_size= options.size();
  ost<<loop_size<<std::endl;
  for(int i=0;i<loop_size;i++;)
  {
    ost<<options[i];
  };
}














std::ostream& operator<<(std::ostream& ost, const Desktop& desktop) {
    ost << "Desktop includes";
    for(auto o : desktop.options) ost << "\n  " << *o;
    return ost;
}
