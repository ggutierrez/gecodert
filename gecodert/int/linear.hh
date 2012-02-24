#ifndef __GECODERT__INT_LINEAR_HH__
#define __GECODERT__INT_LINEAR_HH__

#include <gecodert/gecodert.hh>
#include <gecodert/int.hh>

namespace GecodeRT {

  void linear(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r, int c);
  void linear(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r, CtVar y);
  void linear(GecodeSpace& home, const std::vector<int>& a, const std::vector<CtVar>& x, IntRelType r, int c);
  void linear(GecodeSpace& home, const std::vector<int>& a, const std::vector<CtVar>& x, IntRelType r, CtVar y);

}

#endif
