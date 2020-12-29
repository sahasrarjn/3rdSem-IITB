#! /bin/bash

for i in {0..9}
do
    echo "Running on case $i"
    time ./a.out  < "problem1/${i}.in" > "temp"
    diff "problem1/${i}.out" "temp"
done
