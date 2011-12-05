#include <gecodert/int/distinct.hh>

namespace GecodeRT {
  void distinct(GecodeSpace& home, const std::vector<CtVar>& list){
    
    Gecode::IntVarArgs v;
    for(const CtVar& cv : list){
      v << home.intVar(cv);
    }
    
    Gecode::distinct(home,v);
    
  }
}

