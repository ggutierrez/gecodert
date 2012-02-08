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
    -e '/Gecode::/s/, IntConLevel icl=ICL_DEF);/);\n}/g' \
    -e '/Gecode::/s/Home //g' \
    -e '/Gecode::/s/\<IntVar \([^ ]*\)\>/home.intVar(\1)/g' \
    -e '/Gecode::/s/\<IntVarArgs\& \([^ ]*\)\>/home.toIntVarArgs(\1)/g' \
    -e '/Gecode::/s/\<IntSet\& \([^ ]*\)\>/IntSet(home.toIntArgs(\1))/g' \
    -e '/Gecode::/s/\<IntArgs\& \([^ ]*\)\>/Gecode::IntArgs(\1)/g' \
    -e '/Gecode::/s/\<int\>//g' \
    -e '/Gecode::/s/\&//g' \
    -e '/Gecode::/s/const//g' /tmp/prot.cpp

#Headers
sed -i -e '/void /s/, IntConLevel icl=ICL_DEF);/){/g' \
    -e '/void /s/, IntConLevel=ICL_DEF//g' \
    -e '/void /s/Home home/GecodeSpace\& home/g' \
    -e '/void /s/\<IntVar\>/CtVar/g' \
    -e '/void /s/\<BoolVar\>/CtVar/g' \
    -e '/void /s/\<SetVar\>/CtVar/g' \
    -e '/void /s/\<IntVarArgs\>/std::vector<CtVar>\&/g' \
    -e '/void /s/\<BoolVarArgs\>/std::vector<CtVar>\&/g' \
    -e '/void /s/\<SetVarArgs\>/std::vector<CtVar>\&/g' \
    -e '/void /s/\<IntSet\>/std::vector<int>\&/g' \
    -e '/void /s/\<IntArgs\>/std::vector<int>\&/g' \
    -e '/void /s/\&\&/\&/g' /tmp/prot.cpp

#Show File
cat /tmp/prot.cpp