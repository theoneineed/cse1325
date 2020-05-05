#ifndef __ITEM_H
#define __ITEM_H


#include <string>
#include <cstring>
#include <iostream>
#include <exception>
#include <vector>
#include <iomanip>

class Item{
  private:
    std::string _name;
    double _price;


  public:
    Item();
    Item(std::string name, double price);
    std::string name() const;
    double cost() const;
    friend std::ostream& operator<<(std::ostream& ost, const Item& item);
    friend std::istream& operator>>(std::istream& ist, Item& item);

};

#endif
