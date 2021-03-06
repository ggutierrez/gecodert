#! /usr/bin/env python
# adapted from http://stackoverflow.com/questions/6820350/ctags-multi-line-c-function-prototypes

import re
import sys

# concat to one line
file_str = ''
try:
    read_from=open(sys.argv[1])
    for line in read_from.readlines():
        file_str += line
except IndexError:
    print("Error: Need to pass the input file")

write_to=sys.stdout

# remove all /* */ comments
file_str = re.sub('/\*(.|[\r\n])*?\*/', '', file_str)

# remove '//' comments
file_str = re.sub('//.*', '', file_str)

# split on '\n'
file_as_list = file_str.splitlines(True)

# strip everything
for index in range(len(file_as_list)):
    file_as_list[index] = file_as_list[index].strip()

# add in newlines where appropriate
for line in file_as_list:
    # if the line ends in ';' or '}'
    if line.endswith(';') or line.endswith('}'):
        # append a newline to the stripped line
        write_to.write(line.strip() + '\n')
    else:
        # append a space to the stripped line
        write_to.write(line.strip() + ' ')
