#include "order.h"

Order::Order(Customer& customer) : _customer{customer} {}

Order::~Order() {}

int Order::add_product(Desktop& desktop) {_products.push_back(&desktop); return _products.size()-1;}

double Order::price() const {
    double pr = 0;
    for(auto p : _products) pr += p->price();
    return pr;
}


Order::Order (std::istream& ist)
{
  //ist>>_customer>>_products;
  int loop_size;
  ist>>loop_size;
  ist>>order._customer;
  //My thought process behind this is same as when prof. showed us for hexdump where first three characters were read to find the file extension
  for(int i=0;i<loop_size;i++)
  {
    order._products.push_back(Desktop* {ist});
  };

}

/*Reminder of architecture: A customer goes to a STORE and wants to ORDER something, in his order, he can have different and as many
 DESKTOPs as he wannts and each desktop has different OPTIONS to reconfigure the desktop */
void Order::save (std::ostream& ost)
{
  // ost<<order._customer<<order._products<<std::endl;
  int loop_size= order._products.size();
  ost<<loop_size<<std::endl;
  ost<<order._customer<<std::endl;
  for(int i=0;i<loop_size;i++)
  {
    ost<<order._products[i];
  };

}



std::ostream& operator<<(std::ostream& ost, const Order& order) {
    ost << "Customer: " << order._customer;
    for(auto p : order._products) ost << "\n  " << *p << "\n  Price: $" << p->price() << "\n";
    ost << "\nTotal price: $" << order.price();
    return ost;
}
