#include <gecodert/gecodert.hh>
#include <iostream>

using namespace std;
using namespace GecodeRT;

class Money : public GecodeSpace {

public:
  Money(void); 
};

Money::Money(void) {
  newIntVar(0,10);
  newIntVar(-142424,10);
  newIntVar(0,10);
  newIntVar(0,10);
  newIntVar(0,10);
  cout << "In Money constructor" << endl;
}

int main(void) {
  Money m;
  cout << "Running" << endl;
  return 0;
}
