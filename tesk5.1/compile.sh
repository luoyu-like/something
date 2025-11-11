#!/bin/bash
echo "Compliling Defined Property Demo..."
mkdir -p build
g++ -std=c++17 -I. -o build/tesk5.1 main.cpp person.cpp
if[ $? -eq 0 ];then
    echo "Compilation susseccful!"
    echo"Running program.."
    echo"===================="
    ./build/main
else
    echo"Compolation failed!"
    exit 1
fi 