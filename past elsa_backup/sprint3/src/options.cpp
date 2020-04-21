#include "options.h"

//puclicma duita thapna chha

Options::Options(std::string name, double cost) : _name{name}, _cost{cost} {}

Options::~Options() {}

double Options::cost() {return _cost;}

std::string Options::to_string() const
{
    return _name + " ($" + std::to_string(_cost) + ")";
}


Options::Options (std::istream& ist)
{
  std::getline(ist, _name); //Read the name as an entire line
  ist>>_cost;
  ist.ignore(32767,'\n');//Skip all whitespace through next '\n', leave pointer at start of next line
}


void Options::save (std::ostream& ost)
{
  ost<<_name<<'\n'<<_cost<<std::endl;
}





std::ostream& operator<<(std::ostream& ost, const Options& options)
{
    ost << options.to_string();
    return ost;
}
