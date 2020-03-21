#ifndef __CUSTOMER_H
#define __CUSTMER_H

#include <string>
#include <ostream>

class Customer {
  public:
    Customer(std::string name, std::string phone, std::string email);

  private:
    std::string _name;
    std::string _phone;
    std::string _email;

};

#endif
