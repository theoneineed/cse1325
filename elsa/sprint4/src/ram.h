#ifndef __RAM_H
#define __RAM_H

#include <string>
#include <iostream>
#include<fstream>
class Ram {
  public:
    Ram(std::string name, double const, int gb);
    virtual ~Ram();
    Ram(std::istream& ist);
  protected:
    int _gb;
};

#endif
