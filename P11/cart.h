#ifndef __CART_H
#define __CART_H

#include <cstring>
#include <iostream>
#include "item.h"
#include <string>

class Cart{
  private:
    std::string _customer;
    typedef std::vector <Item*> Items;
    Items _items;
  public:
    Cart(std::string customer);
    virtual ~Cart();
    Cart(const Cart& cart);
    Cart& operator = (const Cart& cart);
    void add_item(Item& item);
    double cost();
    typedef Items::iterator iterator;
    typedef Items::const_iterator const_iterator;
    iterator begin();
    iterator end();
    std::vector<Item*> vector_getter()const;
    std::string customer_name()const;


};

#endif
