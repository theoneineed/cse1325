#ifndef __OPTIONS_H
#define __OPTIONS_H

#include "Customer.h"
#include <string>
#include <ostream>

class Options
 {
  public:
    Options(std::string name, double cost);
    virtual ~Options();
    double cost();
    std::string to_string ();
    friend std::ostream& operator<<(std::ostream& ost, const Options& options);

  private:
    std::string _name;
    double _cost;
};

#endif
