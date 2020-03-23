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
    price+=options::cost();
  }
  return price;
}
