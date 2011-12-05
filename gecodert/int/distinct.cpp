#include <gecodert/int/distinct.hh>

void distinct(GecodeSpace& home, const vector<CtVar>& list){

  Gecode::IntVarArgs v;
  for(const CtVar& cv : list){
    v << home.intVar(cv);
  }
  
  Gecode::distinct(home,v);

}


