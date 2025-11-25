#!/bin/bash
set -e

# If one argument is given → run a specific file
if [[ $# -eq 1 ]]; then
    base="$1"
    cpp="${base}.cpp"
    input="${base}.txt"
    exe="${base}.exe"
    output="${base}-output.txt"

    if [[ ! -f "$cpp" ]]; then
        echo "Error: $cpp not found"
        exit 1
    fi
    if [[ ! -f "$input" ]]; then
        echo "Error: $input not found"
        exit 1
    fi

    echo "Compiling $cpp..."
    g++ -std=c++17 "$cpp" -o "$exe"

    echo "Running $base..."
    ./"$exe" < "$input" > "$output"

    rm -f "$exe"
    echo "→ Output saved to $output"
    exit 0
fi

# If no argument → run all
echo "Usage:"
echo "  ./run.sh            # run all"
echo "  ./run.sh DxPy       # run a specific file"