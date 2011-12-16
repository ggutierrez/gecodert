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
PROTOTYPES=`./props.sh | grep ${PROPAGATOR}`

cat > ${OUTPUTDIR}'/'${PROPAGATOR}.cpp <<EOF

#include <gecodert/${MODULE}/${PROPAGATOR}.hh>

using namespace std;

namespace GecodeRT {

${PROTOTYPES}

}
EOF

sed 's/);/) { \nBODY\n }/g' ${OUTPUTDIR}'/'${PROPAGATOR}.cpp 

emacs -batch ${OUTPUTDIR}'/'${PROPAGATOR}.cpp -l ${HERE}/emacs-format-file -f emacs-format-function
