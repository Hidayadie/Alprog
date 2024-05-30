#!/bin/sh

echo -n "Masukkan nilai: "
read A
if [ $A -gt 100 ]
then
	:
else
	echo "ok"
fi
