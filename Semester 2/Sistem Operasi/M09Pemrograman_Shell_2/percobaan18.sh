#!/bin/sh

F1() {
	echo "Fungsi F1"
	return 1
}
echo "Menggunakan fungsi 1"
F1
echo $?

# 2
echo "\nModifikasi fungsi"
F2() {
	Honor=10000
	echo "Fungsi F2"
	return 1
}
echo "Menggunakan fungsi 2"
F2
echo "Nilai balik adalah $?"
echo "Honor = $Honor"


echo "\nMemodifikasi Fungsi"
F3() {
	local Gaji=10000
	echo "Fungsi 3"
	return 1
}
echo "Menggunakan fungsi 3"
F3
echo "Nilai balik: $?"
echo "Gaji: $Gaji"
