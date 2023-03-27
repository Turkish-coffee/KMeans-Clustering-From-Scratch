#!/bin/zsh
g++ main.cpp -o prog
./prog
source /opt/miniconda3/bin/activate MLenv
python3 ./test.py 
