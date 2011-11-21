#include <gecodert/gecodert.hh>

using namespace Gecode;

namespace GecodeRT {
  
  GecodeSpace::GecodeSpace(void) {}
  
  GecodeSpace::~GecodeSpace(void) {}
  
  GecodeSpace::GecodeSpace(bool share, GecodeSpace& sp) {
    for(unsigned int i = 0; i < iv.size(); i++)
      iv[i].update(*this, share, sp.iv[i]);
  }
  
  Gecode::Space* GecodeSpace::copy(bool share) {
    return new GecodeSpace(share, *this);
  }
  
  CtVar GecodeSpace::newIntVar(int min, int max) {
    IntVar v(*this, IntSet(min, max));
    unsigned int index = iv.size();
    iv.push_back(v);
    std::cout << "An integer variable should be created with min " 
	      << (int)v.min() << " and max " << (int)v.max() << std::endl;
    CtVar t('i', index);
    std::cout << t << std::endl;
    return t;
  }
}
