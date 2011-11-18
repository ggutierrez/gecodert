#include <tuple>
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

  template<class Tuple, std::size_t N>
  struct TuplePrinter{
    static void print(std::ostream& o, const Tuple& t){
      TuplePrinter<Tuple,N-1>::print(o,t);
      o << ", " << std::get<N-1>(t);
    }
  };
  template<class Tuple>
  struct TuplePrinter<Tuple, 1>{
    static void print(std::ostream& o, const Tuple& t){
      o << std::get<0>(t);
    }
  };
  
  template<class... Args>
  std::ostream& operator<<(std::ostream& o, const std::tuple<Args...>& t){
    typedef const std::tuple<Args...>& tuple_t;
    static const int num = sizeof...(Args);
    o << "(";
    TuplePrinter<tuple_t,num>::print(o,t);
    return o << ")";
  }
  
  tupla GecodeSpace::newIntVar(int min, int max) {
    IntVar v(*this, IntSet(min, max));
    unsigned int index = iv.size();
    iv.push_back(v);
    cout << "An integer variable should be created with min " << (int)v.min() 
	 << " and max " << (int)v.max() << endl;
    tupla t('i', index);
    cout << "tupla: " << t << endl;
    return t;
  }
}
