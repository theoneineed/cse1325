#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iostream>
#include <string>
#include <stdlib>
/*  The executable members of Product are as follows:
The constructor should initialize _name and _cost to the matching parameters, and _quantity to 0.
Throw a runtime exception if _cost is negative.*/

int cart (int sum, int item)
{
  return (sum+item);
};
class Product

{

protected:
  int _quantity;
  double _cost;
  string _name;

public:
  Product(string name, double cost):_name(name),_cost(cost){}
  virtual Product {};
  ~Product();
  int set_quantity(int quantity)
  {

  }

  virtual double price() const;

  friend std::ostream& operator<<(std::ostream& ost, const Product& product);


};

class Taxed: public Product{
private:
  double tax;
public:
  Taxed(string name, double cost):_name(name),_cost(cost){}
  virtual void Taxed();
  ~Taxed();
  static void set_tax_rate(double sales tax){};

};

class Taxfree: public Product
{
public:
  Taxfree(string name, double cost):_name(name),_cost(cost){}
  virtual void Taxfree();
  ~Taxfree();
  virtual double price() const override;
};




/*
Write a main function that predefines several taxed and taxfree grocery items. In the main loop:
• List all of the taxable and taxfree items you predefine (at least 3 of each).
• Ask the user to select an item with an associated quantity.
• Perform data validation on their input.
• If invalid, throw an exception (which you must catch and handle) on e.g., negative quantities or
undefined grocery items, then restart the loop.
• If valid, add the selection to their "cart" (e.g., vectors in main).
• List of both sets of items in the cart and a cart total price (sum of all price() methods).
• Then allow them to "buy" the items, e.g., by entering a quantity of 0 or via a menu selection.
*/




#endif
