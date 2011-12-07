#include <gecodert/gecodert.hh>
#include <gecode/search.hh>

using namespace Gecode;

namespace GecodeRT {

  GecodeSpace::GecodeSpace(void) {}
  
  GecodeSpace::~GecodeSpace(void) {}
  
  GecodeSpace::GecodeSpace(bool share, GecodeSpace& sp)
    : Gecode::Space(share,sp), iv(sp.iv), bv(sp.bv), sv(sp.sv){
    for(unsigned int i = 0; i < iv.size(); i++)
      iv[i].update(*this, share, sp.iv[i]);
    for(unsigned int i = 0; i < bv.size(); i++)
      bv[i].update(*this, share, sp.bv[i]);
    for(unsigned int i = 0; i < sv.size(); i++)
      sv[i].update(*this, share, sp.sv[i]);
  }
  
  
  Gecode::Space* GecodeSpace::copy(bool share) {
    return new GecodeSpace(share, *this);
  }
  
  const IntVar& GecodeSpace::intVar(const CtVar& v) const {
    return iv.at(v.index_);
  }

  const BoolVar& GecodeSpace::boolVar(const CtVar& v) const {
    return bv.at(v.index_); 
  }

  const SetVar& GecodeSpace::setVar(const CtVar& v) const {
    return sv.at(v.index_); 
  }
  
  CtVar GecodeSpace::newIntVar(int min, int max) {
    IntVar v(*this, IntSet(min, max));
    unsigned int index = iv.size();
    iv.push_back(v);
    return CtVar('i', index);
  }

  CtVar GecodeSpace::newBoolVar() {
    BoolVar v(*this,0,1);
    unsigned int index = bv.size();
    bv.push_back(v);
    return CtVar('b', index);
  }

  CtVar GecodeSpace::newSetVar(IntSet glb, IntSet lub) {
    SetVar v(*this, glb, lub);
    unsigned int index = sv.size();
    sv.push_back(v);
    return CtVar('s', index);
  }
  
  Gecode::IntVarArgs GecodeSpace::toIntVarArgs(std::vector<CtVar> v){
    IntVarArgs x;
    for (const CtVar& cv : v) {
      x << intVar(cv);
    }
    return x;
  }
  
  std::ostream& GecodeSpace::dump(std::ostream& os) const {
    os << "Variables: " << std::endl;
    int i = 0;
    for (const IntVar& v : iv) {
      os << "\t" << i << ": " << v << std::endl;
      i++;
    }
    int j = 0;
    for (const BoolVar& v : bv) {
      os << "\t" << j << ": " << v << std::endl;
      j++;
    }
    int k = 0;
    for (const SetVar& v : sv) {
      os << "\t" << k << ": " << v << std::endl;
      k++;
    }
    return os;
  }

  /*
   * Branching on a space
   */
  void branch(GecodeSpace& home, const std::vector<CtVar>& v) {
    std::cout << "Should post a brancher" << std::endl;
    
    if(v[0].isIntVar()){
      IntVarArgs x;
      for (const CtVar& cv : v) {
	x << home.intVar(cv);
      }
      Gecode::branch(home,x,Gecode::INT_VAR_SIZE_MIN,Gecode::INT_VAL_MIN);
    } else if(v[0].isBoolVar()){
      BoolVarArgs x;
      for (const CtVar& cv : v) {
	x << home.boolVar(cv);
      }
      Gecode::branch(home,x,Gecode::INT_VAR_SIZE_MIN,Gecode::INT_VAL_MIN);
    } else if(v[0].isSetVar()){	
      SetVarArgs x;
      for (const CtVar& cv : v) {
	x << home.setVar(cv);
      }
      Gecode::branch(home,x,Gecode::SET_VAR_SIZE_MIN,Gecode::SET_VAL_MIN_INC);
    } 
  }
  
  /*
   * Search
   */
  void search(GecodeSpace& root) {
    DFS<GecodeSpace> e(&root);
    while (GecodeSpace *s = e.next()) {
      std::cout << "Solution found" << std::endl;
      s->dump(std::cout);
      delete s;
    }
  }
}
