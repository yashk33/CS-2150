#!/bin/bash
#averagetime.sh

read dictionary
read grid

t1=`./a.out $dictionary $grid | tail -1`
t2=`./a.out $dictionary $grid | tail -1`
t3=`./a.out $dictionary $grid | tail -1`
t4=`./a.out $dictionary $grid | tail -1`
t5=`./a.out $dictionary $grid | tail -1`

sum=`expr $t1 + $t2 + $t3 + $t4 + $t5`
count=5

echo "Average Run Time (milliseconds):"
echo `expr $sum / $count`


