#ifndef __GECODERT__INT_REL_HH__
#define __GECODERT__INT_REL_HH__

#include <gecodert/gecodert.hh>
#include <gecodert/int.hh>

namespace GecodeRT {

  /// Post propagator for $ x_0 \sim_r x_1$.
  void rel(GecodeSpace& home, CtVar x0, IntRelType r, CtVar x1);

  /// Post propagator for $ x_i \sim_r y $ for all $0\leq i<|x|$. 
  void rel(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r, CtVar y);

  /// Propagates $ x \sim_r c$.
  void rel(GecodeSpace& home, CtVar x0, IntRelType r, int c);

  /// Propagates $ x_i \sim_r c $ for all $0\leq i<|x|$. 
  void rel(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r, int c);

  /// Post propagator for $ (x_0 \sim_r x_1)\Leftrightarrow b$.
  void rel(GecodeSpace& home, CtVar x0, IntRelType r, CtVar x1, CtVar b);

  /// Post propagator for $(x \sim_r c)\Leftrightarrow b$. 
  void rel(GecodeSpace& home, CtVar x, IntRelType r, int c, CtVar b);

  /// Post propagator for relation among elements in x. 
  void rel(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r);

  /// Post propagator for relation between x and y. 
  void rel(GecodeSpace& home, const std::vector<CtVar>& x, IntRelType r, const std::vector<CtVar>& y);
      
}

#endif
