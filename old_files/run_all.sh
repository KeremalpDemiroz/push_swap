#!/bin/bash

# Sayaç başlat
count=0

# Python ile permütasyonları bir değişkene al
permutations=$(python3 - << 'EOF'
import itertools
for p in itertools.permutations([0,1,2,3]):
    print(" ".join(map(str,p)))
EOF
)

# Satır satır işle
while IFS= read -r ARG; do
    # Hamleleri say
    MOVE_COUNT=$(./a.out $ARG | wc -l)

    # Sadece 12'den büyükse yazdır
    if [ "$MOVE_COUNT" -gt 12 ]; then
        echo "=========="
        echo "$ARG"
        echo "Instruction count: $MOVE_COUNT"
        echo "Checker:"
        ./a.out $ARG | ./checker_linux $ARG
        # Sayaç artır
        count=$((count + 1))
    fi
done <<< "$permutations"

# Toplam sayıyı yazdır
echo "======================================"
echo "12'den büyük hamleye sahip permütasyon sayısı: $count"
