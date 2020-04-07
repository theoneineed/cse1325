#ifndef __ORDER_H
#define __ORDER_H

#include "customer.h"
#include "desktop.h"

class Order {
  public:
    Order(Customer* customer);
    //I don't understand why star is supposed to be use but it said in question, replace & with star.

    virtual ~Order();

    int add_product(Desktop& desktop);

    double price() const;

    Order(std::istream& ist);

    void save (std::ostream& ost);

    friend std::ostream& operator<<(std::ostream& ost, const Order& order);
    //added  two new methods compared to sprint 1
  private:
    Customer* _customer;
    std::vector<Desktop*> _products;
};

#endif
