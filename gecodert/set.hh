#ifndef __GECODERT__SET_HH__
#define __GECODERT__SET_HH__

#include <gecode/set.hh>

namespace GecodeRT {

  enum SetVarBranch {
    SET_VAR_NONE = Gecode::SET_VAR_NONE,   
    SET_VAR_RND = Gecode::SET_VAR_RND,        
    SET_VAR_DEGREE_MIN = Gecode::SET_VAR_DEGREE_MIN, 
    SET_VAR_DEGREE_MAX = Gecode::SET_VAR_DEGREE_MAX, 
    SET_VAR_AFC_MIN = Gecode::SET_VAR_AFC_MIN,    
    SET_VAR_AFC_MAX = Gecode::SET_VAR_AFC_MAX,    
    SET_VAR_MIN_MIN = Gecode::SET_VAR_MIN_MIN,    
    SET_VAR_MIN_MAX = Gecode::SET_VAR_MIN_MAX,    
    SET_VAR_MAX_MIN = Gecode::SET_VAR_MAX_MIN,    
    SET_VAR_MAX_MAX = Gecode::SET_VAR_MAX_MAX,    
    SET_VAR_SIZE_MIN = Gecode::SET_VAR_SIZE_MIN,   
    SET_VAR_SIZE_MAX = Gecode::SET_VAR_SIZE_MAX,   
    SET_VAR_SIZE_DEGREE_MIN = Gecode::SET_VAR_SIZE_DEGREE_MIN, 
    SET_VAR_SIZE_DEGREE_MAX = Gecode::SET_VAR_SIZE_DEGREE_MAX, 
    SET_VAR_SIZE_AFC_MIN = Gecode::SET_VAR_SIZE_AFC_MIN, 
    SET_VAR_SIZE_AFC_MAX = Gecode::SET_VAR_SIZE_AFC_MAX  
  };

  
  enum SetValBranch {
    SET_VAL_MIN_INC = Gecode::SET_VAL_MIN_INC, 
    SET_VAL_MIN_EXC = Gecode::SET_VAL_MIN_EXC, 
    SET_VAL_MED_INC = Gecode::SET_VAL_MED_INC, 
    SET_VAL_MED_EXC = Gecode::SET_VAL_MED_EXC, 
    SET_VAL_MAX_INC = Gecode::SET_VAL_MAX_INC, 
    SET_VAL_MAX_EXC = Gecode::SET_VAL_MAX_EXC, 
    SET_VAL_RND_INC = Gecode::SET_VAL_RND_INC, 
    SET_VAL_RND_EXC = Gecode::SET_VAL_RND_EXC  
  };

}

#endif


