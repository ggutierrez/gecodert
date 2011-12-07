#ifndef __GECODERT_INT_DISTINCT_HH__
#define __GECODERT_INT_DISTINCT_HH__

#include <iostream>
#include <vector>
#include <gecodert/gecodert.hh>
#include <gecodert/exceptions/exceptions.hh>

using namespace std;

namespace GecodeRT {
  
  /// Post propagator for \f$ x_i+n_i\neq x_j+n_j\f$ for all \f$0\leq i\neq j<|x|\f$
  void distinct(GecodeSpace& home, const std::vector<CtVar>& x);
  
}



#endif
