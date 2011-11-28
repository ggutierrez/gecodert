#include <gecodert/gecodert.hh>
#include <gecode/search.hh>

using namespace Gecode;

namespace GecodeRT {

  GecodeSpace::GecodeSpace(void) {}
  
  GecodeSpace::~GecodeSpace(void) {}
  
  // GecodeSpace::GecodeSpace(bool share, GecodeSpace& sp)
  //   : Gecode::Space(share,sp), iv(sp.iv)  {
  //   for(unsigned int i = 0; i < iv.size(); i++)
  //     iv[i].update(*this, share, sp.iv[i]);
  // }

  GecodeSpace::GecodeSpace(bool share, GecodeSpace& sp)
    : Gecode::Space(share,sp), sv(sp.sv)  {
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
    return CtVar('b', index);
  }

  CtVar GecodeSpace::newBoolVar(int min, int max) {
    BoolVar v(*this, min, max);
    unsigned int index = bv.size();
    bv.push_back(v);
    return CtVar('b', index);
  }

  CtVar GecodeSpace::newSetVar(int glbMin, int glbMax, int lubMin, int lubMax) {
    SetVar v(*this, IntSet(glbMin, glbMax), IntSet(lubMin, lubMax));
    unsigned int index = sv.size();
    sv.push_back(v);
    return CtVar('s', index);
  }

  std::ostream& GecodeSpace::dump(std::ostream& os) const {
    os << "Variables: " << std::endl;
    int i = 0;
    for (const IntVar& v : iv) {
      os << "\t" << i << ": " << v << std::endl;
      i++;
    }
    return os;
  }

  std::ostream& GecodeSpace::dump2(std::ostream& os) const {
    os << "Variables: " << std::endl;
    int i = 0;
    for (const SetVar& v : sv) {
      os << "\t" << i << ": " << v << std::endl;
      i++;
    }
    return os;
  }
  /*
   * Branching on a space
   */
  void branch(GecodeSpace& home, const std::vector<CtVar>& iv) {
    std::cout << "Should post a brancher" << std::endl;
    IntVarArgs x;
    for (const CtVar& v : iv) {
      // add type detection
      x << home.intVar(v);
    }
    Gecode::branch(home,x,Gecode::INT_VAR_SIZE_MIN,Gecode::INT_VAL_MIN);;
  }


    void branch2(GecodeSpace& home, const std::vector<CtVar>& sv) {
    std::cout << "Should post a brancher" << std::endl;
    SetVarArgs x;
    for (const CtVar& v : sv) {
      // add type detection
      x << home.setVar(v);
    }
    Gecode::branch(home,x,Gecode::SET_VAR_SIZE_MIN,Gecode::SET_VAL_MIN_INC);;
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

  void search2(GecodeSpace& root) {
    DFS<GecodeSpace> e(&root);
    while (GecodeSpace *s = e.next()) {
      std::cout << "Solution found" << std::endl;
      s->dump2(std::cout);
      delete s;
    }
  }

}
