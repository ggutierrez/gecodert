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
  CtVar x = newIntVar(1,3);
  CtVar y = newIntVar(1,3);
  distinct(*this,{x,y});
  rel(*this,x,IRT_NQ,2);
  rel(*this,y,IRT_NQ,2);
  branch(*this,{x,y});
  cout << "In Test constructor" << endl;
}

int main(void) {
  Test m;
  search(m);
  return 0;
}
