#include <gecodert/int/distinct.hh>


namespace GecodeRT {
  void distinct(GecodeSpace& home, const std::vector<CtVar>& x) {
    
    for(unsigned int i; i< x.size(); i++){
      if(!x[i].isIntVar()){
	CopiaEx(1);
      }
      else{
	Gecode::IntVarArgs l;
	cout << "Passdis1" << endl;
	l=home.toIntVarArgs(x);
	cout << "Passdis2" << endl;
	Gecode::distinct(home,l);
      }
    }
  }
}
