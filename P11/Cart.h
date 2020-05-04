#ifndef __CART_H
#define __CART_H
class Cart{
  private:
    std::string _customer;
    typedef std::vector <Item*> Items;
    Items _items;
  public:
    Cart(std::string customer);
    virtual ~Cart();
    Cart& operator = (const Cart& cart);
    void add_item(Item& item);
    double cost();
    typedef Items::iterator iterator;
    typedef Items::const_iterator const_iterator;
    iterator begin(){return _items.begin();}
    iterator end(){return _items.end();}


}

#endif
