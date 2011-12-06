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

  std::vector<CtVar> l {s, e, n, d, m, r, y};

  rel(*this, s, IRT_NQ, 0);
  rel(*this, m, IRT_NQ, 0);
  distinct(*this, l); 
 
  std::vector<int> c(4+4+5);
  std::vector<CtVar> x {s, e, n, d, m, o, r, e, m, o, n, e, y};
  
  c[0] = 1000; c[1] = 100; c[2] = 10; c[3] = 1;
  //  x[0] = s;    x[1] = e;   x[2] = n;  x[3] = d;
  c[4] = 1000; c[5] = 100; c[6] = 10; c[7] = 1;
  //  x[4] = m;    x[5] = o;   x[6] = r;  x[7] = e;
  c[8] = -10000; c[9] = -1000; c[10] = -100; c[11] = -10; c[12] = -1;
  //  x[8] = m;      x[9] = o;     x[10] = n;    x[11] = e;   x[12] = y;

  linear(*this, c, x, IRT_EQ, 0);
 
  branch(*this, l);
}

int main(void) {
  Money m;
  search(m);
  return 0;
}
