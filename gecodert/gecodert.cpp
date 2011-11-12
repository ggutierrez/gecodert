#include <gecodert/gecodert.hh>

namespace GecodeRT {
  
  GecodeSpace::GecodeSpace(void) {}

  GecodeSpace::~GecodeSpace(void) {}

  GecodeSpace::GecodeSpace(bool share, GecodeSpace& sp) {
    for (unsigned int i = 0; i < iv.size(); i++)
      iv[i].update(*this,share,sp.iv[i]);
  }

  Gecode::Space* GecodeSpace::copy(bool share) {
    return new GecodeSpace(*this);
  }

  void GecodeSpace::newIntVar(int min, int max) {
    std::cout << "An integer varible should be created" << std::endl;
  }
}
