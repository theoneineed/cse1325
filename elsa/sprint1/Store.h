#ifndef __STORE_H
#define __STORE_H

#include <string>
#include <ostream>
#include <vector>

class Store {
private:
  std::vector<Customer> customer;
  std::vector<Options*> options;
  std::vector<Desktop> desktops;
  std::vector<Order> orders;
public:
  void add_customer(Customer& customer);
  int num_customers();
  Customer& customer(int index);
  void add_option(Options& option);
  int num_options();
  Options& option(int index);
  int new_desktop();
  void add_option(int option, int desktop);
  int num_desktops();
  Desktop& desktop(int index);
  int new_order(int customer);
  void add_desktop(int desktop, int order);
  int num_orders();
  Order& order(int index);



  // public:
  //   Product(std::string name, double cost);
  //   virtual ~Product();
  //   void set_quantity(int num);
  //   virtual double price() const = 0;
  //   friend std::ostream& operator<<(std::ostream& ost, const Product& product);
  // protected:
  //   std::string _name;
  //   double _cost;
  //   int _num;

};

#endif
