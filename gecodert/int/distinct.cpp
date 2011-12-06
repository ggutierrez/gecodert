#include <gecodert/int/distinct.hh>

namespace GecodeRT {
  void distinct(GecodeSpace& home, const std::vector<CtVar>& x) {
    Gecode::IntVarArgs l;
    l=home.toIntVarArgs(x);
    Gecode::distinct(home,l);
  }
}
