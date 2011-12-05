#ifndef __GECODERT_INT_DISTINCT_HH__
#define __GECODERT_INT_DISTINCT_HH__
                      
#include <vector>
#include <gecode/kernel.hh>
#include <gecode/int.hh>
#include <gecodert/gecodert.hh>

namespace GecodeRT {
  void distinct(GecodeSpace& home, const std::vector<CtVar>& list);
}
#endif

