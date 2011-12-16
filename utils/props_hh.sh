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

cat > ${OUTPUTDIR}'/'${PROPAGATOR}.hh <<EOF
#ifndef __GECODERT__${MODULEGUARD}_${PROPAGATORGUARD}_HH__
#define __GECODERT__${MODULEGUARD}_${PROPAGATORGUARD}_HH__

#include <gecodert/gecodert.hh>
#include <gecodert/${MODULE}.hh>

namespace GecodeRT {

${PROTOTYPES}

}

#endif
EOF

emacs -batch ${OUTPUTDIR}'/'${PROPAGATOR}.hh -l ${HERE}/emacs-format-file -f emacs-format-function
