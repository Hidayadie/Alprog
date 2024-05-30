#!/bin/sh

Pilih=1
while :
do
	echo "1. Siapa yang aktif"
	echo "2. Tanggal hari ini"
	echo "3. Kalender"
	echo "4. Keluar"
	echo "	pilihan: \c"
	read Pilih
	if [ $Pilih -eq 4 ]
	then
		break
	fi
	clear
done
echo "Program selesai"
