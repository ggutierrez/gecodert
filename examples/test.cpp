#include <gecodert/gecodert.hh>
#include <iostream>

using namespace std;
using namespace GecodeRT;

class Test : public GecodeSpace {

public:
  Test(void); 
};

Test::Test(void) {
  CtVar x = newBoolVar(0,1);
  cout << "Pass1" << x << endl;
  branch2(*this,{x});
  cout << "Pass2" << x << endl;
  cout << "In Test constructor" << endl;
}

int main(void) {
  Test m;
  search2(m);
  return 0;
}
