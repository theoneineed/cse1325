#ifndef __DESKTOP_H
#define; __DESKTOP_H

#include <string>
#include <ostream>
#include <vector>

class Desktop {
  public:
    void add_option(Options& option);
    double price();
    friend std::ostream& operator<<(std::ostream& ost, const Product& product);

  private:
    std::vector<Options*> options;
};

#endif
