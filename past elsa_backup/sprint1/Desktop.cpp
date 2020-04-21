#include "Desktop.h"
#include <iomanip>
#include <vector>
#include "Options.h"


void Desktop::add_option(Options& option)
{
  options.push_back(&option);

}

double Desktop::price() const
{
  int price=0;
  for(int i=0;i<options.size();i++)
  {
    price+=options[i]->cost();

  }
  return price;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop) {
    ost << desktop.price();
    return ost;
}
