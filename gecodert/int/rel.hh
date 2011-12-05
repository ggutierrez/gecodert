#ifndef __GECODERT__INT_REL_HH__
#define __GECODERT__INT_REL_HH__

#include <gecodert/gecodert.hh>
#include <gecodert/int.hh>

namespace GecodeRT {
  
  /// Propagates $ x \sim_r c$. 
  void rel(GecodeSpace& home, CtVar x0, IntRelType r, int c);
  
}

#endif
