#include "item.h"
#include <iostream>

Item::Item(){}
Item::Item(std::string name, double price):_name{name},_price{price} {}

double Item::cost() const
{
    return _price;
}
std::string Item::name() const
{
  return _name;
}
//operator <<
std::ostream& operator<<(std::ostream& ost, const Item& item)
{
	ost << "$ " <<std::setw(8)<<std::fixed<<std::setprecision(2) << item._price <<"\t"<< item._name;
	return ost;
}

//operator >>
std::istream & operator >> (std::istream &ist,  Item& item){

	std::string n_line ;
	getline(ist,n_line,'\n');
	std::string x = "new";
	if(n_line=="") throw x;
	std::stringstream checker(n_line);
	std::string s;
	int i =0;
	std::vector<std::string> v;
	    while(getline(checker, s, ' '))
    {
    	v.push_back(s);
    }
    if (v.size() == 1){
    			std::string error = "Invalid Price: '"+v[0]+"' has 'No price'";
        		throw error;
    }
    else if(v.size() >1){
    	std::string name;
    	for(i = 0;i<v.size()-1;i++)
    		name += v[i]+" ";

    	item._name = name;
    	        	try{

        		item._price = std::stod(v[v.size()-1]);
        	}
        	catch(std::exception)
        	{
        		std::string error = "Invalid Price: '"+item._name+"' has '"+v[v.size()-1]+"'";
        		throw error;
        	}


    }
	return ist;
}
