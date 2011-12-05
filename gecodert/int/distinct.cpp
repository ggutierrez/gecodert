#include <gecodert/int/distinct.hh>

namespace GecodeRT {
  void distinct(GecodeSpace& home, const std::vector<CtVar>& list){
    
    Gecode::IntVarArgs v;
    v=home.toIntVarArgs(home,list);
    Gecode::distinct(home,v);
    
  }
}

