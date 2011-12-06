#ifndef __GECODERT__INT_LINEAR_HH__
#define __GECODERT__INT_LINEAR_HH__

#include <gecodert/gecodert.hh>
#include <gecodert/int.hh>

namespace GecodeRT {

  /// Post propagator for $\sum_{i=0}^{|x|-1}a_i\cdot x_i\sim_r c$. 
  void linear(GecodeSpace& home, const std::vector<int>& a, const std::vector<CtVar>& x, IntRelType r, int c);
      
}

#endif
