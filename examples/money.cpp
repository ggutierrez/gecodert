#include <gecodert/gecodert.hh>
#include <iostream>

using namespace std;
using namespace GecodeRT;

class Money : public GecodeSpace {

public:
  Money(void); 
};

Money::Money(void) {
  CtVar x = newIntVar(0,10);
  branch(*this,{x});
  cout << "In Money constructor" << endl;
}

int main(void) {
  Money m;
  search(m);
  return 0;
}
