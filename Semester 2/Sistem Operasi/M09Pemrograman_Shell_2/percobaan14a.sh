#!/bin/sh

echo "1. Siapa yang aktif"
echo "2. Tanggal hari ini"
echo "3. Kalender bulan ini"
echo -n "pilihan: "
read Pilih
case $Pilih in
1)
	echo "yang aktif saat ini"
	who
	;;
2)
	echo "tanggal hari ini"
	date
	;;
3)
	echo "hmm"
	;;
*)
	echo "salahh"
	;;

esac
