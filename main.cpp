
// pls stop yelling at me

#include "dict.hpp"
#include <string>
using std::string;

#define DICT Dict<string, string>
template class Hashtbl<string,string>;
template class DICT;


int main()  {
  const int n = 3;
  // why can't I use new?
  DICT d = DICT(n);
  std::cout << "Yay, dict initialised\n";
  // eventually free
  delete &d;
  return 0;
}
