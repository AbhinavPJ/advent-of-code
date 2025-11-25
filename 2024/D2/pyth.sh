#!/bin/bash
set -e

# If user passed an argument, run only that DxPy
if [[ $# -eq 1 ]]; then
    base="$1"
    py="${base}.py"
    input="${base}.txt"
    output="${base}-output.txt"

    if [[ ! -f "$py" ]]; then
        echo "Error: $py not found"
        exit 1
    fi

    if [[ ! -f "$input" ]]; then
        echo "Error: $input not found"
        exit 1
    fi

    echo "Running $py..."
    python3 "$py" < "$input" > "$output"

    echo "→ Output saved to $output"
    exit 0
fi

# Otherwise: run ALL DxPy.py files
for py in D*P*.py; do
    base="${py%.py}"
    input="${base}.txt"
    output="${base}-output.txt"

    if [[ -f "$input" ]]; then
        echo "Running $py..."
        python3 "$py" < "$input" > "$output"
        echo "→ Output saved to $output"
    else
        echo "Skipping $py (no input file)"
    fi
done
