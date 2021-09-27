#!/bin/bash

echo "enter the exponent for counter.cpp:"
read in

if [ $in == "quit" ]
then
    exit 0
fi

clang++ -O0 *.cpp

total=0
itr=5

for (( i=1; i<=itr; i++ ))
do
    echo "Running iteration ${i}..."
    runtime=`./a.out ${in}`
    total=`expr $total + $runtime`
    echo "time taken: ${runtime} ms"
done

echo "5 iterations took ${total} ms"
echo "Average time was "`expr $total / 5` ms
