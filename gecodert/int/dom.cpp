#include <gecodert/int/dom.hh>

using namespace std;

namespace GecodeRT {

  void dom(GecodeSpace& home, CtVar x, int n) {
    Gecode::dom(home, home.intVar(x), n);
  }
  // void dom(GecodeSpace& home, const std::vector<CtVar>& x, int n);
  // void dom(GecodeSpace& home, CtVar x, int l, int m);
  // void dom(GecodeSpace& home, const std::vector<CtVar>& x, int l, int m);
  // void dom(GecodeSpace& home, CtVar x, const std::vector<int>& s);
  // void dom(GecodeSpace& home, const std::vector<CtVar>& x, const std::vector<int>& s);
  // void dom(GecodeSpace& home, CtVar x, int n, CtVar b);
  // void dom(GecodeSpace& home, CtVar x, int l, int m, CtVar b);
  // void dom(GecodeSpace& home, CtVar x, const std::vector<int>& s, CtVar b);

}
