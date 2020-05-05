#include "item.h"
#include "cart.h"
#include <iostream>
#include <string>
#include <exception>



int main(){


	Cart cart{"Random string"};

	std::cout<< "Input name and price of an object (e.g. 'Muffins 2.50'):" << std::endl;


  while(true)
  {
    try
    {
      Item item;
      std::cin>> item;
      cart.add_item(item);
    }
    catch(std::string err)
    {
      if(err=="new")
      {
        break;
      }
      std::cerr << err << std::endl;
    }
  }

for (Cart::iterator i = cart.begin(); i!= cart.end();i++ )
{
	std::cout<<**i<<std::endl;
}

	std::cout<<"   *          *              *            *         *"<<std::endl;

	std::cout<<"$ "<<std::setw(8)<<std::fixed<<std::setprecision(2)<<cart.cost()<<"\tTotal Cost: "<<std::endl;

}
