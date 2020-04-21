#ifndef __CUSTOMER_H
#define __CUSTOMER_H

#include <string>
#include <iostream>
#include<fstream>
class Customer {
  public:
    Customer(std::string name, std::string phone, std::string email);
    friend std::ostream& operator<<(std::ostream& ost, const Customer& customer);
    Customer (std::istream& ist);
    void save (std::ostream& ost);
    //added two public methods
  private:
    std::string _name;
    std::string _phone;
    std::string _email;
    //defining private variable seems kinda sketchy in this case, let me just check it and come back to it
};

#endif
