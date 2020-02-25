#include "Product.h"
#include "logger.h"


int cart_price=0;
std::cout<<"1.Bread:$2.00"<<"\n"<<"2.Chicken: $10.00"<<"\n"<<"3.Milk: $3.00"<<"\n"<<"4.Copy: $4.00 \n"<<std::endl;
std::cin>>"Enter code of item, give a space and enter quantity you want:">>index>>quantity;
if (index==1 || index== 3)
