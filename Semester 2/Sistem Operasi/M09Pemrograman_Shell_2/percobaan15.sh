#!/bin/sh

echo "for Nama in"
for Nama in Hidayat Satrio Adie
do
	echo "Nama adalah: $Nama"
done

echo "for F in *"
for F in *
do
	echo $F
done

echo "for long list"
for F in *.sh
do
	ls -l $F
done

