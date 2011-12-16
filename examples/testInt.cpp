#include <gecodert/gecodert.hh>
#include <gecodert/int/distinct.hh>
#include <gecodert/int/dom.hh>
#include <gecodert/int/linear.hh>
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
  
  CtVar x = newIntVar(0,1);
  // CtVar y = newIntVar(0,1);
  // CtVar z = newIntVar(0,1);
  // CtVar w = newIntVar(0,1);

  dom(*this, x, 1);
  
  //distinct(*this,{1,2,3,4}, {x,y,z,w});
  //  rel(*this, {x,y}, IRT_EQ, {z, w});

  //linear(*this, {5}, {x}, IRT_EQ, 10);
  branch(*this, {x});

}

int main(void) {
  Test m;
  search(m);
  return 0;
}
