#include "Store.h"
#include <iomanip>

void Store::add_customer(Customer& customer)
{}
int Store::num_customers()
{}
Customer& Store::customer(int index)
{}
void Store::add_option(Options& option)
{}
int Store::num_options()
{}
Options& Store::option(int index)
{}
int Store::new_desktop()
{}
void Store::add_option(int option, int desktop)
{}
int Store::num_desktops()
{}
Desktop& Store::desktop(int index)
{}
int Store::new_order(int customer)
{}
void Store::add_desktop(int desktop, int order)
{}
int Store::num_orders()
{}
Order& Store::order(int index)
{}


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
