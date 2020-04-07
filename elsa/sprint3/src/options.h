#ifndef __OPTIONS_H
#define __OPTIONS_H

#include <string>
#include <iostream>

class Options {
  public:
    Options(std::string name, double cost);
    virtual ~Options();
    double cost();
    virtual std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& ost, const Options& options);
    Options (std::istream& ist);
    void save (std::ostream& ost);
    //added two methods compared to sprint 1

  protected:
    std::string _name;
    double _cost;
};

#endif
