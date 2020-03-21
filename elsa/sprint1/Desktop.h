#ifndef __DESKTOP_H
#define; __DESKTOP_H

#include <string>
#include <ostream>
#include <vector>

class Desktop {
  public:
    void add_option(Options& option);
    double price();
  private:
    std::vector<Options*> options;
};

#endif