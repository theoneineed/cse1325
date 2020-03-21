#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <string>
#include <ostream>

class Options
 {
  public:
    Options(std::string name, double cost);
    virtual ~Options();
    double cost();
    std::string to_string();
  private:
    std::string _name;
    double _cost;
};

#endif
