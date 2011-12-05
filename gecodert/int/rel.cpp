#include <iostream>
#include <gecodert/int/rel.hh>
#include <gecodert/int.hh>

using namespace std;

namespace GecodeRT {

  void rel(GecodeSpace& home, CtVar x0, IntRelType r, CtVar x1) {
    Gecode::rel(home, home.intVar(x0), static_cast<Gecode::IntRelType>(r), home.intVar(x1));
  }

  void rel(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r, CtVar y) {
    Gecode::rel(home, home.toIntVarArgs(x), static_cast<Gecode::IntRelType>(r), home.intVar(y));
  }

  void rel(GecodeSpace& home, CtVar x0, IntRelType r, int c) {
    Gecode::rel(home, home.intVar(x0), static_cast<Gecode::IntRelType>(r), c);
  }
  
  void rel(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r, int c) {
    Gecode::rel(home, home.toIntVarArgs(x), static_cast<Gecode::IntRelType>(r), c);
  }
  
  void rel(GecodeSpace& home, CtVar x0, IntRelType r, CtVar x1, CtVar b) {
    Gecode::rel(home, home.intVar(x0), static_cast<Gecode::IntRelType>(r), home.intVar(x1), home.boolVar(b));
  }

  void rel(GecodeSpace& home, CtVar x, IntRelType r, int c, CtVar b) {
    Gecode::rel(home, home.intVar(x), static_cast<Gecode::IntRelType>(r), c, home.boolVar(b));
  }

  void rel(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r) {
    Gecode::rel(home, home.toIntVarArgs(x), static_cast<Gecode::IntRelType>(r));
  }

  void rel(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r, const std::vector<CtVar>& y) {
    Gecode::rel(home, home.toIntVarArgs(x), static_cast<Gecode::IntRelType>(r), home.toIntVarArgs(y));
  }
  
}
