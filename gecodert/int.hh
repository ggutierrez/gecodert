#ifndef __GECODERT__INT_HH__
#define __GECODERT__INT_HH__

#include <gecode/int.hh>

namespace GecodeRT {
  
  enum IntRelType {
    IRT_EQ = Gecode::IRT_EQ, ///< Equality (\f$=\f$)
    IRT_NQ = Gecode::IRT_NQ, ///< Disequality (\f$\neq\f$)
    IRT_LQ = Gecode::IRT_LQ, ///< Less or equal (\f$\leq\f$)
    IRT_LE = Gecode::IRT_LE, ///< Less (\f$<\f$)
    IRT_GQ = Gecode::IRT_GQ, ///< Greater or equal (\f$\geq\f$)
    IRT_GR = Gecode::IRT_GR  ///< Greater (\f$>\f$)    
  };
}

#endif
