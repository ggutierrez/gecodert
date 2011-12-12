#!/bin/bash

grep '(Home home' $1 | paste -s -d"F" | sed -e 's/Home home/GecodeSpace\& home/g' -e "s/\<IntVar\>/CtVar/g" -e "s/\<BoolVar\>/CtVar/wg" -e "s/\<SetVar\>/CtVar/wg" -e "s/\<IntVarArgs\>/std::vector<CtVar>\&/g" -e "s/\<BoolVarArgs\>/std::vector<CtVar>\&/g" -e "s/\<SetVarArgs\>/std::vector<CtVar>\&/g" -e "s/\<IntSet\>/std::vector<int>\&/g" -e "s/\&\&/\&/g" -e "s/,F/);\n/g" > prueba.hh