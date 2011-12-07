#include <gecodert/gecodert.hh>
#include <gecodert/int/distinct.hh>
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
  CtVar x = newBoolVar();
  CtVar y = newBoolVar();
  // CtVar z = newIntVar(0,2);
  // CtVar w = newIntVar(0,2);
  cout << "Pass1" << endl;
  distinct(*this,{x,y});
  //  rel(*this, {x,y}, IRT_EQ, {z, w});
  cout << "Pass2" << endl;
  //linear(*this, {5}, {x}, IRT_EQ, 10);
  branch(*this, {x,y});

}

int main(void) {
  Test m;
  search(m);
  return 0;
}
