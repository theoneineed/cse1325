#include "customer.h"

Customer::Customer(std::string name, std::string phone, std::string email)
    : _name{name}, _phone{phone}, _email{email} {}
    
std::ostream& operator<<(std::ostream& ost, const Customer& customer) {
    ost << customer._name << " (" << customer._phone << "," << customer._email << ")";
    return ost;
}


Customer::Customer (std::istream& ist)
{
  getline(ist,_name);
  ist>>_phone;
  ist.ignore();
  ist>> _email;
  ist.ignore();
  //ist>>_name>>_phone>>_email;
}


void Customer::save (std::ostream& ost)
{
  ost<<_name<<'\n'<<_phone<<'\n'<<_email<<std::endl;
}
