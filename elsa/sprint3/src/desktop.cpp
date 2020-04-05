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
  ist>>_name>>_phone>>_email;
}


void Desktop::save (std::ostream& ost)
{
  ost<<_name<<'\n'<<_phone<<'\n'<<_email<<std::endl;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop) {
    ost << "Desktop includes";
    for(auto o : desktop.options) ost << "\n  " << *o;
    return ost;
}
