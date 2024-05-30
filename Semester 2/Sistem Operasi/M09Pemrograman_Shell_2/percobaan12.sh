#!/bin/sh
expr 5 + 1
A=5
expr $A + 2
expr $A - 4
expr $A * 2
expr $A \* 2
expr $A / 6 + 10
expr 17 % 5

A=5
B=`expr $A + 1`
echo $B
