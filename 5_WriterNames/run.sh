#!/bin/bash

filename=$(basename -- "$1")
basename="${filename%.*}"

g++ -std=c++17 -o "$basename.bin" "$1"

if [ $? -eq 0 ]; then
    ./"$basename.bin" Writers.txt Sretirw.txt
else
    echo "Compilation failed"
fi