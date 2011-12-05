#ifndef __GECODERT_INT_DISTINCT_HH__
#define __GECODERT_INT_DISTINCT_HH__
                      
#include <vector>
#include <gecode/kernel.hh>
#include <gecode/int.hh>
#include <gecodert/gecodert.hh>

using namespace std;
using namespace GecodeRT;

void distinct(GecodeSpace& home, const vector<CtVar>& list);

#endif

