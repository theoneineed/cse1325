#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string input,gender;
    std::cout<< "Please input your father's last name:\n>";
    std::getline(std::cin, input);
    std::cout<< "type m if you are male and f if you are female:\n";
    std::getline(std::cin,gender);
    std::cout<< "do you have a bother or sister?\n";
    std::getline(std::cin,gender);
    std::cout<<"When you get out of Starbucks, what is written on your coffee cup? ";
    std::getline(std::cin,gender);
    std::cout << "Hello "<<gender<<" "<<input<<"!";
}
