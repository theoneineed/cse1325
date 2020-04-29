#ifndef __DESKTOP_H
#define __DESKTOP_H

#include "options.h"
#include <vector>

class Desktop {
  public:
    Desktop();
    void add_option(Options& option);
    double price();
    Desktop(std::istream& ist);
    void save(std::ostream& ost);
    friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
    //added three methods compared to sprint 1
  private:
    std::vector<Options*> options;
};

#endif
