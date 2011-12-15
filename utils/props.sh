#!/bin/bash

# Removes comments
cpp -fpreprocessed /usr/include/gecode/int.hh |

# Extracts only the prototypes
grep -A 4 -B 1 '(Home home,' | sed -e 's/GECODE_INT_EXPORT //g' \
    -e 's/--//g' -e '/int.hh/d' -e '/class/d' -e '/typedef/d' -e '/enum/d' \
    -e '/INT_/d' -e '/private/d' |

# Joins lines
./parser.py /tmp/prototypes |

# Some replacements
sed -e 's/, IntConLevel icl=ICL_DEF//g' -e 's/, IntConLevel=ICL_DEF//g' \
    -e 's/Home home/GecodeSpace\& home/g' \
    -e 's/\<IntVar\>/CtVar/g' -e 's/\<BoolVar\>/CtVar/g' -e 's/\<SetVar\>/CtVar/g' \
    -e 's/\<IntVarArgs\>/std::vector<CtVar>\&/g' -e 's/\<BoolVarArgs\>/std::vector<CtVar>\&/g' \
    -e 's/\<SetVarArgs\>/std::vector<CtVar>\&/g' -e 's/\<IntSet\>/std::vector<int>\&/g' -e 's/\&\&/\&/g' \
    -e 's/^[ \t]*//;s/[ \t]*$//' # Removes all leading and trailing whitespace from end of each line

# -e 's/,F/);\n/g'
