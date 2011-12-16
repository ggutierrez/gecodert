#!/usr/bin/env python

import sys

lines=[]

try:
    f=open(sys.argv[1])
    lines=f.readlines()
except IndexError:
    print("Error: need to pass the file")
    sys.exit()

for line in lines:
    if line.startswith("Gecode::"):
        line=line.replace("GecodeSpace& ", "")
        line=line.replace("CtVar ", "")
        line=line.replace("int ", "")
        # FIXME
        # line=line.replace("const std::vector<CtVar>& ", "home.toIntVarArgs(x)") 
        # FIXME
        #line=line.replace("const std::vector<int>& ", "Gecode::IntArgs(a)")
        line=line.replace("IntRelType ", "static_cast<Gecode::IntRelType>(r)")

#        print(line)

sys.stdout.writelines(lines)
