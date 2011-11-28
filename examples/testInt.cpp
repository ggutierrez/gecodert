#include <gecodert/gecodert.hh>
#include <iostream>

using namespace std;
using namespace GecodeRT;

class Test : public GecodeSpace {

public:
  Test(void); 
};

Test::Test(void) {
  CtVar x = newIntVar(4,12);
  //cout << "Pass1" << x << endl;
  branch(*this,{x});
  //cout << "Pass2" << x << endl;
  cout << "In Test constructor" << endl;
}

int main(void) {
  Test m;
  search(m);
  return 0;
}
