#include "Store.h"
#include <iomanip>
#include <vector>


void Store::add_customer(Customer& customer)
{
  customers.push_back(customer);
}

int Store::num_customers()
{
  return customers.size();
}

Customer& Store::customer(int index)
{
  if(index<customers.size())
  {
    return (customers[index]);
  }
}

void Store::add_option(Options& option)
{
  options.push_back(&option);
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
    return *(options[index]);
  }
}

int Store::new_desktop()
{
  Desktop new_desk;
  desktops.push_back(new_desk);
  int index=desktops.size()-1;
  return index;
  //This is index as this is going to be the last element in the vector which is 1 less than size of the vector
}

void Store::add_option(int option, int desktop)
{
//  Options option_new = Store::new_option(std::string _name, double _cost);
  desktops[desktop].add_option(*(options[option]));
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
    return (desktops[index]);
  }
  else
  {
    std::cout << "index is out of bound" << '\n';
  }
}

int Store::new_order(int customer)
{
  Order new_ord {customers[customer]};
  orders.push_back(new_ord);
  return orders.size()-1;
}

void Store::add_desktop(int desktop, int order)
{
  Desktop desktop_new (std::vector<Options*> options);

  orders[order].add_product(desktops[desktop]);
  //what is happening is new option is being created and will be added to passed indes 'option' in passed indexed 'desktop' in desktops vector

}

int Store::num_orders()
{
  std::cout << orders.size() << '\n';
  return orders.size();
}

Order& Store::order(int index)
{
  if(orders.size()==0){std::cout << "We don't have any orders rn. Please try later." << '\n';}
  if(index<orders.size())
  {
    std::cout<<orders[index]<<"\n";
    return (orders[index]);
  }
  else
  {
    std::cout << "index is out of bound" << '\n';
  }
}
