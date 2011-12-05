#include <gecodert/gecodert.hh>
#include <gecodert/int/rel.hh>
#include <iostream>

using namespace std;
using namespace GecodeRT;

class Money : public GecodeSpace {

public:
  Money(void); 
};

Money::Money(void) {
  CtVar x = newIntVar(0,3);
  rel(*this, x, IRT_NQ, 0);
  branch(*this,{x});
  cout << "In Money constructor" << endl;
}

int main(void) {
  Money m;
  search(m);
  return 0;
}
