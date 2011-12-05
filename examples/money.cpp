#include <gecodert/gecodert.hh>
#include <gecodert/int/rel.hh>
#include <gecodert/int.hh>
#include <gecodert/int/distinct.hh>
#include <iostream>

using namespace std;
using namespace GecodeRT;

class Money : public GecodeSpace {

public:
  Money(void); 
};

Money::Money(void) {
  CtVar s = newIntVar(0,9);
  CtVar e = newIntVar(0,9);
  // CtVar n = newIntVar(0,9);
  // CtVar d = newIntVar(0,9);
  // CtVar m = newIntVar(0,9);
  // CtVar o = newIntVar(0,9);
  // CtVar r = newIntVar(0,9);
  // CtVar y = newIntVar(0,9);
 distinct(*this,{s,e}); 
 rel(*this, s, IRT_EQ, 0);
  rel(*this, e, IRT_LQ, 5);
 
  branch(*this,{s,e});
  cout << "In Money constructor" << endl;
}

int main(void) {
  Money m;
  search(m);
  return 0;
}
