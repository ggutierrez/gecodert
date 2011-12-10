#include <gecodert/gecodert.hh>
#include <gecodert/int.hh>
#include <gecodert/int/distinct.hh>
#include <gecodert/int/linear.hh>
#include <gecodert/int/rel.hh>
#include <iostream>

using namespace GecodeRT;

class Money : public GecodeSpace {

public:
  Money(void); 
};

Money::Money(void) {

  CtVar s = newIntVar(0,9);
  CtVar e = newIntVar(0,9);
  CtVar n = newIntVar(0,9);
  CtVar d = newIntVar(0,9);
  CtVar m = newIntVar(0,9);
  CtVar o = newIntVar(0,9);
  CtVar r = newIntVar(0,9);
  CtVar y = newIntVar(0,9);

  std::vector<CtVar> l {s, e, n, d, m, o, r, y};

  rel(*this, s, IRT_NQ, 0);
  rel(*this, m, IRT_NQ, 0);
  distinct(*this, l); 
 
  std::vector<int> c {1000, 100, 10, 1, 1000, 100, 10, 1, -10000, -1000, -100, -10, -1};
  std::vector<CtVar> x {s, e, n, d, m, o, r, e, m, o, n, e, y};

  linear(*this, c, x, IRT_EQ, 0);
  branch(*this, l);
   
}

int main(void) {
  Money m;
  search(m);
  return 0;
}
