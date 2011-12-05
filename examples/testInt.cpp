#include <gecodert/gecodert.hh>
#include <gecodert/int/distinct.hh>
#include <gecodert/int/rel.hh>
#include <iostream>
#include <vector>

using namespace std;
using namespace GecodeRT;

class Test : public GecodeSpace {

public:
  Test(void); 
};

Test::Test(void) {

  CtVar x = newIntVar(0,2);
  CtVar y = newIntVar(0,2);
  CtVar z = newIntVar(0,2);
  CtVar w = newIntVar(0,2);
  
  rel(*this, {x,y}, IRT_EQ, {z, w});

  branch(*this, {x,y,z,w});

}

int main(void) {
  Test m;
  search(m);
  return 0;
}
