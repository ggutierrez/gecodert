
#include <gecodert/int/linear.hh>

using namespace std;

namespace GecodeRT {

  void linear(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r, int c){
    Gecode::linear(home, home.toIntVarArgs(x), static_cast<Gecode::IntRelType>(r), c);
  }

  void linear(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r, CtVar y){
    Gecode::linear(home, home.toIntVarArgs(x), static_cast<Gecode::IntRelType>(r), home.intVar(y));
  }

  void linear(GecodeSpace& home, const std::vector<int>& a, const std::vector<CtVar>& x, IntRelType r, int c){
    Gecode::linear(home, Gecode::IntArgs(a), home.toIntVarArgs(x), static_cast<Gecode::IntRelType>(r), c);
  }

  void linear(GecodeSpace& home, const std::vector<int>& a, const std::vector<CtVar>& x, IntRelType r, CtVar y){
    Gecode::linear(home, Gecode::IntArgs(a), home.toIntVarArgs(x), static_cast<Gecode::IntRelType>(r), home.intVar(y));
  }

}
