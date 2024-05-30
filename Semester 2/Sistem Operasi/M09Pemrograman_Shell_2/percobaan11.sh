#!/bin/sh
echo -n "Income: "
read Income
if [ $Income -ge 0 -a $Income -le 10000 ]
then
	Biaya=10
elif [ $Income -gt 10000 -a $Income -le 25000 ]
then
	Biaya=25
else
	Biaya=35
fi
echo "Biaya = $Biaya"
