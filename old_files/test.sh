#!/bin/bash

# Python ile permütasyon üret ve satır satır işle
python3 - << 'EOF' | while read ARG; do
import itertools
for p in itertools.permutations([0,1,2,3]):
    print(" ".join(map(str,p)))
EOF

    echo "=========="
    echo "$ARG"

    ./a.out $ARG

    echo "Instruction count:"
    ./a.out $ARG | wc -l

    echo "Checker:"
    ./a.out $ARG | ./checker_linux $ARG
done
