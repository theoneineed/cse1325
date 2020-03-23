#include "Store.h"
#include <iomanip>

void Store::add_customer(Customer& customer)
{
  customers.push_back(&customer);
}

int Store::num_customers()
{
  return customers.size();
}

Customer& Store::customer(int index)
{
  if(index<customers.size())
  {
    return &(customers[index]);
  }
}

void Store::add_option(Options& option)
{

}

int Store::num_options()
{}

Options& Store::option(int index)
{}

int Store::new_desktop()
{
  Desktop new_desk{std::vector<Options*> options};
  desktops.push_back(&new_desk);
  int index=desktops.size()-1;
  return index;
  //This is index as this is going to be the last element in the vector which is 1 less than size of the vector
}

void Store::add_option(int option, int desktop)
{
  int desktop_new = Store::new_desktop();
  desktops.insert(desktop,desktop_new); //desktop is index passed and new_desktop is the new one that is actually inserted
}

int Store::num_desktops()
{}

Desktop& Store::desktop(int index)
{}

int Store::new_order(int customer)
{
  Order new_ord {Customer& _customer, std::vector< Desktop* > _products};
  return &new_ord;
}

void Store::add_desktop(int desktop, int order)
{}

int Store::num_orders()
{}

Order& Store::order(int index)
{}
