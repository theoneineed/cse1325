#ifndef __DESKTOP_H
#define __DESKTOP_H

#include <string>
#include <ostream>
#include <vector>
#include "Options.h"
class Desktop {
  public:
    void add_option(Options& option);
    double price() const;
    friend std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);

  private:
    std::vector<Options*> options;
};

#endif
