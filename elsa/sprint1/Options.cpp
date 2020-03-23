#include "Options.h"
#include <iomanip>
/*Both Desktop and Store use pointers to track Option instamces which indicates
that this will become the base class for derived classes storing tech specific info*/
Options::options (std::string name, double cost):_name{name},_cost{cost}
{

}

/*For sprint 1, we simply track the name and cost of each option.
We'll want the operator << function for it*/

Options::~Options(){}

double Options::cost()
{
  //This will show the price of the device that will be added to computer
}

std::string Options::to_string()
{
  //although the pdf file says to_string function to be virtual, UML doesn't say that
  std::to_string(_cost);
  //As this only makes sense, seeing name is already string
}
