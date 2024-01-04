#!/bin/bash

filename=$(basename -- "$1")
basename="${filename%.*}"

g++ -std=c++17 -o "$basename" "$1"

if [ $? -eq 0 ]; then
    ./"$basename"
else
    echo "Compilation failed"
fi