#include <iostream>
#include <gecodert/int/rel.hh>

using namespace std;

namespace GecodeRT {
  
  void rel(GecodeSpace& home, CtVar x0, IntRelType r, int c){
    Gecode::rel(home, home.intVar(x0), static_cast<Gecode::IntRelType>(r), c);
  }
  
}
