#include <gecodert/gecodert.hh>

using namespace std;
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
  
  void GecodeSpace::newIntVar(int min, int max) {
    IntVar v(*this, min, max);
    iv.push_back(v);
    //cout << "myvector stores " << (int) iv.size() << " numbers.\n";
    cout << "An integer variable should be created with min " << (int)v.min() 
	 << " and max " << (int)v.max() << endl;
  }
}
