#!/bin/bash
set -e

for cpp in D*P*.cpp; do
    base="${cpp%.cpp}"           # D1P1
    input="${base}.txt"          # D1P1.txt
    exe="${base}.exe"
    output="${base}-output.txt"  # D1P1-output.txt

    if [[ -f "$input" ]]; then
        echo "Compiling $cpp..."
        g++ -std=c++17 "$cpp" -o "$exe"

        echo "Running $base..."
        ./"$exe" < "$input" > "$output"

        rm -f "$exe"
        echo "→ Output saved to $output"
    else
        echo "Skipping $cpp (no input file)"
    fi
done