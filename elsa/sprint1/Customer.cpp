#include "Customer.h"
#include <iomanip>

Customer::Customer (std::string name, std::string phone, std::string email):_name{name},_phone{phone},_email{email}
{
  //Insert code here
}
// Product::Product(std::string name, double cost)
//        : _name{name}, _cost{cost}, _num{0} {
//     if(_cost < 0) throw std::runtime_error{"Negative cost for " + _name};
// }
// Product::~Product() { }
//
// void Product::set_quantity(int num) {_num = num;}
//
// std::ostream& operator<<(std::ostream& ost, const Product& product) {
//     ost << product._name << " (";
//     if(product._num > 0) ost << product._num << " @ ";
//     ost << "$" << std::fixed << std::setprecision(2) << product._cost << ")";
//     return ost;
}
