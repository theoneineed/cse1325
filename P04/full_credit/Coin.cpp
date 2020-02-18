

#include <iostream>
#include <string>
#include <sstream> //got it from geeksforgeeks

class Coin
{
private:
  Coin_size _size;
  Year _year;
  string* _notes;
public:
  Coin(size:Size, year:Year);
  Coin (rhs:const Coin&);
  friend std::ostream& operator= (rhs: const Coin& ): Coin&;
  friend std::ostream& operator<<(ostream& ost, const Coin& coin);
  std::string add_note(s);
  friend std::istream& operator>>(istream& ist, Coin& coin);

};
