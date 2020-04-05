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
  ist>>_name>>_phone>>_email;
}


void Order::save (std::ostream& ost)
{
  ost<<_name<<'\n'<<_phone<<'\n'<<_email<<std::endl;
}



std::ostream& operator<<(std::ostream& ost, const Order& order) {
    ost << "Customer: " << order._customer;
    for(auto p : order._products) ost << "\n  " << *p << "\n  Price: $" << p->price() << "\n";
    ost << "\nTotal price: $" << order.price();
    return ost;
}
