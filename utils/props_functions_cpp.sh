#!/bin/bash

# Removes comments
cpp -fpreprocessed /usr/include/gecode/int.hh |

# Extracts only the prototypes                                          
grep -A 4 -B 1 '(Home home,' | sed -e 's/GECODE_INT_EXPORT //g' \
    -e 's/--//g' -e '/int.hh/d' -e '/class/d' -e '/typedef/d' -e '/enum/d' \
    -e '/INT_/d' -e '/private/d' > /tmp/prototypes2

# Joins lines
./parser.py /tmp/prototypes2 | 

# Generates body for cpp
sed -e 's \(.*\) \1\1 ' > /tmp/prot.cpp  
sed -i -e 's/; /;\nXXX/g' -e 's/;v/;\nXXXv/g' /tmp/prot.cpp

# Indents file
emacs -batch /tmp/prot.cpp -l ${PWD}/emacs-format-file -f emacs-format-function 

# Replacements for the functions of cpp
# Body
sed -i -e '/XXX/s/void /Gecode::/g' \
    -e '/XXX/s/XXX//g' \
    -e '/Gecode::/s/, IntConLevel icl=ICL_DEF);/);\n};/g' \
    -e '/Gecode::/s/Home //g' \
    -e '/Gecode::/s/\<IntVar\>/home.intVar/g' \
    -e '/Gecode::/s/\<IntVarArgs\>/home.toIntVarArgs/g' \
    -e '/Gecode::/s/\<IntSet\>/IntSet(home.toIntArgs)\&/g' \
    -e '/Gecode::/s/\<IntArgs\>/home.toIntArgs/g' \
    -e '/Gecode::/s/\&//g' \
    -e '/Gecode::/s/const//g' /tmp/prot.cpp 

#Headers
sed -i -e 's/, IntConLevel icl=ICL_DEF);/){/g' \
    -e 's/, IntConLevel=ICL_DEF//g' \
    -e 's/Home home/GecodeSpace\& home/g' \
    -e 's/\<IntVar\>/CtVar/g' \
    -e 's/\<BoolVar\>/CtVar/g' \
    -e 's/\<SetVar\>/CtVar/g' \
    -e 's/\<IntVarArgs\>/std::vector<CtVar>\&/g' \
    -e 's/\<BoolVarArgs\>/std::vector<CtVar>\&/g' \
    -e 's/\<SetVarArgs\>/std::vector<CtVar>\&/g' \
    -e 's/\<IntSet\>/std::vector<int>\&/g' \
    -e 's/\<IntArgs\>/std::vector<int>\&/g' \
    -e 's/\&\&/\&/g' /tmp/prot.cpp

