#include "Order.h"
#include <iomanip>

Order::Order (Customer& customer):_customer{customer}
{
  //just a constructor
}
Order::~Order(){}

int Order::add_product(Desktop& desktop)
{
  _products.push_back(&desktop);
}

double Order::price()
{
  int price1=0;
  for(int i=0;i<_products.size();i++)
  {
    price1+=Desktop::price();
  }
  return price1;
}


std::ostream& operator<<(std::ostream& ost, const Order& order) {
    ost << Order._customer<<" needs to pay "<<Order::price();
    return ost;
}
