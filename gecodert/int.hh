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
  
  enum IntVarBranch {
    INT_VAR_NONE = Gecode::INT_VAR_NONE,        
    INT_VAR_RND = Gecode::INT_VAR_RND,             
    INT_VAR_DEGREE_MIN = Gecode::INT_VAR_DEGREE_MIN,      
    INT_VAR_DEGREE_MAX = Gecode::INT_VAR_DEGREE_MAX,      
    INT_VAR_AFC_MIN = Gecode::INT_VAR_AFC_MIN,         
    INT_VAR_AFC_MAX = Gecode::INT_VAR_AFC_MAX,         
    INT_VAR_MIN_MIN = Gecode::INT_VAR_MIN_MIN,         
    INT_VAR_MIN_MAX = Gecode::INT_VAR_MIN_MAX,         
    INT_VAR_MAX_MIN = Gecode::INT_VAR_MAX_MIN,         
    INT_VAR_MAX_MAX = Gecode::INT_VAR_MAX_MAX,         
    INT_VAR_SIZE_MIN = Gecode::INT_VAR_SIZE_MIN,        
    INT_VAR_SIZE_MAX = Gecode::INT_VAR_SIZE_MAX,        
    INT_VAR_SIZE_DEGREE_MIN = Gecode::INT_VAR_SIZE_DEGREE_MIN, 
    INT_VAR_SIZE_DEGREE_MAX = Gecode::INT_VAR_SIZE_DEGREE_MAX, 
    INT_VAR_SIZE_AFC_MIN = Gecode::INT_VAR_SIZE_AFC_MIN,    
    INT_VAR_SIZE_AFC_MAX = Gecode::INT_VAR_SIZE_AFC_MAX,    
    INT_VAR_REGRET_MIN_MIN = Gecode::INT_VAR_REGRET_MIN_MIN,
    INT_VAR_REGRET_MIN_MAX = Gecode::INT_VAR_REGRET_MIN_MAX,
    INT_VAR_REGRET_MAX_MIN = Gecode::INT_VAR_REGRET_MAX_MIN,
    INT_VAR_REGRET_MAX_MAX = Gecode::INT_VAR_REGRET_MAX_MAX
  };
  
  enum IntValBranch {
    INT_VAL_MIN = Gecode::INT_VAL_MIN,       
    INT_VAL_MED = Gecode::INT_VAL_MED,       
    INT_VAL_MAX = Gecode::INT_VAL_MAX,       
    INT_VAL_RND = Gecode::INT_VAL_RND,       
    INT_VAL_SPLIT_MIN = Gecode::INT_VAL_SPLIT_MIN, 
    INT_VAL_SPLIT_MAX = Gecode::INT_VAL_SPLIT_MAX, 
    INT_VAL_RANGE_MIN = Gecode::INT_VAL_RANGE_MIN, 
    INT_VAL_RANGE_MAX = Gecode::INT_VAL_RANGE_MAX, 
    INT_VALUES_MIN = Gecode::INT_VALUES_MIN,    
    INT_VALUES_MAX = Gecode::INT_VALUES_MAX     
  };

}

#endif
