#include "Customer.h"
#include <iomanip>

Customer::Customer (std::string name, std::string phone, std::string email):_name{name},_phone{phone},_email{email}
{
  //Insert code here
}
std::ostream& operator<<(std::ostream& ost, const Customer& customer) {
    ost << customer._name << customer._phone << customer._email;
    return ost;
}
