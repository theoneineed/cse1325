#include <iostream>
#include <string>
#include <sstream>

int main()
{
    std::string input;
    std::cout<< "Please enter your name:\n>";
    std::getline(std::cin, input);
    std::cout << "Hello "<<input<<"!";
}
