#!/bin/bash

# Removes comments
cpp -fpreprocessed /usr/include/gecode/int.hh |

# Extracts only the prototypes                                          
grep -A 4 -B 1 '(Home home,' | sed -e 's/GECODE_INT_EXPORT //g' \
    -e 's/--//g' -e '/int.hh/d' -e '/class/d' -e '/typedef/d' -e '/enum/d' \
    -e '/INT_/d' -e '/private/d' > /tmp/prototypes

# Joins lines
./parser.py /tmp/prototypes |

# Replacements for the functions of cpp
sed -e 's/, IntConLevel icl=ICL_DEF//g' -e 's/, IntConLevel=ICL_DEF//g' \
    -e 's/Home home/home/g' \
    -e 's/\<IntVar\>/home.intVar/g' \
    -e 's/\<IntVarArgs\>/home.toIntVarArgs/g' \
    -e 's/\<IntSet\>/IntSet(home.toIntArgs)\&/g' \
    -e 's/\<IntArgs\>/home.toIntArgs/g' -e 's/\&\&/\&/g' \
    -e 's/void /Gecode::/g' \
    -e 's/^[ \t]*//;s/[ \t]*$//' # Removes all leading and trailing whitespace from end of each line

# -e 's/,F/);\n/g'
