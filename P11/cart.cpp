#include "cart.h"

Cart::Cart(std::string customer):_customer{customer}
{}

Cart:: ~Cart()
{
  for (int i=0;i<_items.size();i++)
  {
    delete _items[i];
  }
}


std::string Cart::customer_name()const{
	return _customer;
}


std::vector <Item*> Cart::vector_getter() const{
  return _items;
}


Cart::Cart(const Cart& cart)
{
  _customer=cart.customer_name();
  std::vector<Item*> vec= cart.vector_getter();
  for (int i=0; i<vec.size();i++)
  {
    _items.push_back(new Item{vec[i]->name(),vec[i]->cost()});
  }
}

Cart& Cart::operator = (const Cart& cart)
{
  if(this!= &cart)
  {
    _customer=cart.customer_name();
    std::vector<Item*> v = cart.vector_getter();
    for (int i = 0;i<v.size();i++)
    {
      _items.push_back(new Item{v[i]->name(),v[i]->cost()});
    }
    return *this;
  }
}

void Cart::add_item(Item& item)
{
  _items.push_back(new Item{item.name(),item.cost()});

}



Cart::iterator Cart::begin()
{
  return _items.begin();
}

Cart::iterator Cart::end()
{
  return _items.end();
}

double Cart::cost()
{
  double total_cost=0.00;
  for (Cart::iterator p=begin(); p!=end();++p)
  {
    total_cost+= (*p)->cost();
  }
  return total_cost;
}
