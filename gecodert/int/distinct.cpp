#include <gecodert/int/distinct.hh>

namespace GecodeRT {
  void distinct(GecodeSpace& home, const std::vector<CtVar>& x) {
    Gecode::distinct(home, home.toIntVarArgs(x));
  }

  void distinct(GecodeSpace& home, const std::vector<int>& n, const std::vector<CtVar>& x) {
    Gecode::distinct(home, Gecode::IntArgs(n), home.toIntVarArgs(x));
  }

}
