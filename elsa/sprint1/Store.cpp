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
  int index=0;
  std::cout << "Insert the index" << '\n';
  std::cin >> index;
  if (index>-1||index<options.size())
  {
    options.insert(index, &option);
    //This inserts the option to the options vector at desired index
  }
  else
  {
    std::cout << "Index out of bound" << '\n';
  }
}

int Store::num_options()
{
  std::cout << options.size() << '\n';
  return options.size();
}

Options& Store::option(int index)
{
  if(index<options.size())
  {
    return &(options[index]);
  }
}

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
  Options option_new = Store::new_option(std::string _name, double _cost);
  desktops[desktop].insert(option,option_new);
  //what is happening is new option is being created and will be added to passed indes 'option' in passed indexed 'desktop' in desktops vector
}

int Store::num_desktops()
{
  std::cout << desktops.size() << '\n';
  return desktops.size();
}

Desktop& Store::desktop(int index)
{
  if(index<desktops.size())
  {
    return &(desktops[index]);
  }
  else
  {
    std::cout << "index is out of bound" << '\n';
  }
}

int Store::new_order(int customer)
{
  Order new_ord {Customer& _customer, std::vector< Desktop* > _products};
  return &new_ord;
}

void Store::add_desktop(int desktop, int order)
{
  Desktop desktop_new (std::vector<Options*> options);

  orders[order].insert(desktop,desktop_new)

  //what is happening is new option is being created and will be added to passed indes 'option' in passed indexed 'desktop' in desktops vector

}

int Store::num_orders()
{
  std::cout << orders.size() << '\n';
  return orders.size();
}

Order& Store::order(int index)
{
  if(index<orders.size())
  {
    return &(orders[index]);
  }
  else
  {
    std::cout << "index is out of bound" << '\n';
  }
}
