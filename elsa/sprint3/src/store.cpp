#include "store.h"

Store::Store()
{
  std::vector<Customer> customers;
  std::vector<Options*>  options;
  std::vector<Desktop>  desktops;
  std::vector<Order>    orders;
}
/*Reminder of architecture: A customer goes to a STORE and wants to ORDER something, in his order, he can have different and as many
 DESKTOPs as he wannts and each desktop has different OPTIONS to reconfigure the desktop */

Store::Store(std::istream& ist)
{
  int no_cust, no_opt, no_desk, no_ord;
  ist>>no_cust;
  // ist>>no_cust>>no_opt>>no_desk>>no_ord;
  for (int i=0;i<no_cust;i++)
  {
    customers.push_back(Customer{ist});
  }
}

/*Reminder of architecture: A customer goes to a STORE and wants to ORDER something, in his order, he can have different and as many
 DESKTOPs as he wannts and each desktop has different OPTIONS to reconfigure the desktop */
void Store::save (std::ostream& ost)
{
  int no_cust, no_opt, no_desk, no_ord;
  no_cust=customers.size();
  no_opt= options.size();
  no_desk= desktops.size();
  no_ord= orders.size();
  ost<<no_cust<<std::endl;
  // ost<<no_cust<<no_opt<<no_desk<<no_ord<<std::endl;
  for(int i=0;i<no_cust;i++)
  {
    ost<<customers[i];
    // for(int j=0;j)
  }

}







void Store::add_customer(Customer& customer) {customers.push_back(customer);}
int Store::num_customers() {return customers.size();}
Customer& Store::customer(int index) {return customers.at(index);}

//
// Options
//
void Store::add_option(Options& option) {options.push_back(new Options{option});}
int Store::num_options() {return options.size();}
Options& Store::option(int index) {return *options.at(index);}

//
// Products
//
int Store::new_desktop() {
    desktops.push_back(Desktop{});
    return desktops.size()-1;
}
void Store::add_option(int option, int desktop) { // to desktop
    desktops.at(desktop).add_option(*options.at(option));
}
int Store::num_desktops() {return desktops.size();}
Desktop& Store::desktop(int index) {return desktops.at(index);}

//
// Orders
//
int Store::new_order(int customer) {
    orders.push_back(Order{customers.at(customer)});
    return orders.size()-1;
}

void Store::add_desktop(int desktop, int order) { // to order
    orders.at(order).add_product(desktops.at(desktop));
}
int Store::num_orders() {return orders.size();}
Order& Store::order(int index) {return orders.at(index);}
