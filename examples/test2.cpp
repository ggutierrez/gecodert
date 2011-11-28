#include <gecodert/gecodert.hh>
#include <iostream>

using namespace std;
using namespace GecodeRT;

class Money : public GecodeSpace {

public:
  Money(void); 
};

Money::Money(void) {
  CtVar x = newSetVar(0,10,0,11);
  branch2(*this,{x});
  cout << "In Money constructor" << endl;
}

int main(void) {
  Money m;
  search2(m);
  return 0;
}
