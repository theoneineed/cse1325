#include "Desktop.h"
#include <iomanip>


void Desktop::add_option (Options& option)
{
  options.push_back(&option);

}

double Desktop::price()
{
  int price=0;
  for(int i=0;i<options.size();i++)
  {
    price+=options[i].cost();
  }
  return price;
}

std::ostream& operator<<(std::ostream& ost, const Desktop& desktop) {
    ost << desktop.price();
    return ost;
}
