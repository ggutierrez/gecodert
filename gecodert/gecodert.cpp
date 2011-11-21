#include <gecodert/gecodert.hh>
#include <gecode/search.hh>

using namespace Gecode;

namespace GecodeRT {
  
  GecodeSpace::GecodeSpace(void) {}
  
  GecodeSpace::~GecodeSpace(void) {}
  
  GecodeSpace::GecodeSpace(bool share, GecodeSpace& sp)
    : Gecode::Space(share,sp), iv(sp.iv)  {
    for(unsigned int i = 0; i < iv.size(); i++)
      iv[i].update(*this, share, sp.iv[i]);
  }
  
  Gecode::Space* GecodeSpace::copy(bool share) {
    return new GecodeSpace(share, *this);
  }
  
  const IntVar& GecodeSpace::var(const CtVar& v) const {
    return iv.at(v.index_);
  }
  
  CtVar GecodeSpace::newIntVar(int min, int max) {
    IntVar v(*this, IntSet(min, max));
    unsigned int index = iv.size();
    iv.push_back(v);
    return CtVar('i', index);
  }

  std::ostream& GecodeSpace::dump(std::ostream& os) const {
    os << "Integer variables: " << std::endl;
    int i = 0;
    for (const IntVar& v : iv) {
      os << "\t" << i << ": " << v << std::endl;
      i++;
    }
    return os;
  }
  /*
   * Branching on a space
   */
  void branch(GecodeSpace& home, const std::vector<CtVar>& vars) {
    std::cout << "Should post a brancher" << std::endl;
    IntVarArgs x;
    for (const CtVar& v : vars) {
      x << home.var(v);
    }
    Gecode::branch(home,x,Gecode::INT_VAR_SIZE_MIN,Gecode::INT_VAL_MIN);;
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
