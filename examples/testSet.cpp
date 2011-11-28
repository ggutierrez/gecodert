#include <gecodert/gecodert.hh>
#include <iostream>

using namespace std;
using namespace Gecode;
using namespace GecodeRT;

class Test2 : public GecodeSpace {

public:
  Test2(void); 
};

Test2::Test2(void) {
  IntSet glb (0,2);
  IntSet lub (0,5);
  CtVar x = newSetVar(glb,lub);
  branch(*this,{x});
  cout << "In Test2 constructor" << endl;
}

int main(void) {
  Test2 m;
  search(m);
  return 0;
}
