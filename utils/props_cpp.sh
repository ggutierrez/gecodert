#!/bin/bash

EXPECTED_ARGS=2

if [ $# -ne $EXPECTED_ARGS ]
then
  echo "Usage: `basename $0` module propagator"
  exit
fi

HERE=${PWD}
OUTPUTDIR='/tmp'
MODULE=$1
PROPAGATOR=$2
MODULEGUARD=`echo ${MODULE} | tr '[:lower:]' '[:upper:]'`
PROPAGATORGUARD=`echo ${PROPAGATOR} | tr '[:lower:]' '[:upper:]'`
PROTOTYPES=`./props.sh | grep ${PROPAGATOR} | sed -e 's \(.*\) \1\1 ' -e 's/;void /;Gecode::/'`

cat > ${OUTPUTDIR}'/'${PROPAGATOR}.cpp <<EOF

#include <gecodert/${MODULE}/${PROPAGATOR}.hh>

using namespace std;

namespace GecodeRT {

${PROTOTYPES}

}
EOF

cat ${OUTPUTDIR}'/'${PROPAGATOR}.cpp | sed -e 's/);Gecode/) { \nGecode/g' -e 's/);/);\n}\n/g' |
awk '/GecodeSpace& /{c++;if(c==2){sub("GecodeSpace& ","");c=0}}1' |
awk '/const std::vector<CtVar>& /{c++;if(c==2){sub("const std::vector<CtVar>& ","");c=0}}1' |
awk '/const std::vector<int>& /{c++;if(c==2){sub("const std::vector<int>& ","");c=0}}1' |
awk '/int /{c++;if(c==2){sub("int ","");c=0}}1' |
awk '/CtVar /{c++;if(c==2){sub("CtVar ","");c=0}}1'

emacs -batch ${OUTPUTDIR}'/'${PROPAGATOR}.cpp -l ${HERE}/emacs-format-file -f emacs-format-function
