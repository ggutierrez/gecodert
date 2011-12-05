#include <iostream>
#include <gecodert/int/rel.hh>
#include <gecodert/int.hh>

using namespace std;

namespace GecodeRT {

  void rel(GecodeSpace& home, CtVar x0, IntRelType r, CtVar x1) {
    Gecode::rel(home, home.intVar(x0), static_cast<Gecode::IntRelType>(r), home.intVar(x1));
  }

  void rel(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r, CtVar y) {
    Gecode::IntVarArgs iv;
    for(const CtVar& cv : x){
      iv << home.intVar(cv);
    }
    Gecode::rel(home, iv, static_cast<Gecode::IntRelType>(r), home.intVar(y));
  }

  void rel(GecodeSpace& home, CtVar x0, IntRelType r, int c) {
    Gecode::rel(home, home.intVar(x0), static_cast<Gecode::IntRelType>(r), c);
  }
  
  void rel(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r) {
    Gecode::IntVarArgs iv;
    for(const CtVar& cv : x){
      iv << home.intVar(cv);
    }
    Gecode::rel(home, iv, static_cast<Gecode::IntRelType>(r));
  }
  
  
}
