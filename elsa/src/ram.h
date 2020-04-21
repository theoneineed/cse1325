#ifndef __RAM_H
#define __RAM_H

#include <string>
#include <iostream>
#include<fstream>
#include "options.h"
enum class Ram_subtypes
{
    onegb,twogb,threegb,fourgb,fivegb,sixgb
};

class Ram {
  public:
    Ram(std::string name, double const, int gb);
    virtual ~Ram();
    Ram(std::istream& ist);
    std::string to_string() const override;
    void save(std::ostream& ost) override;
    std::string gb1();
  protected:
    int _gb;
};

#endif
