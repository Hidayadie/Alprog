#!/bin/bash
# 1
Nama=amir
test $Nama = amir
echo $?
test $Nama = boris
echo $?

# 2
echo -n "Nama: "
read Nama
if test "$Nama" = amir
then
	echo "Selamat datang $Nama"
else
	echo "Halo, $Nama"
fi

# 3
echo -n "Nama anda:"
read Nama
if [ "$Nama" = amir ]
then
	echo "Halo $Nama"
else
	echo "Anda bukan amir ya.."
fi
