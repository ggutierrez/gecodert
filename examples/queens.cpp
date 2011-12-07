#include <gecodert/gecodert.hh>
#include <gecodert/int/distinct.hh>
#include <iostream>

using namespace GecodeRT;

class Queens : public GecodeSpace {

public:
  Queens(void); 
};

Queens::Queens(void) {
  
  int n = 8;

  std::vector<CtVar> q;
  for(int i=0; i<n; i++) {
    q.push_back(newIntVar(0, n-1));
  }
  
  std::vector<int> v1;
  for(int i=0; i<n; i++) {
    v1.push_back(i);
  }

  std::vector<int> v2;
  for(int i=0; i<n; i++) {
    v2.push_back(-i);
  }
  
  distinct(*this, v1, q);
  distinct(*this, v2, q);
  distinct(*this, q);
 
  branch(*this, q);
}

int main(void) {
  
  Queens q;
  search(q);
  return 0;
}
