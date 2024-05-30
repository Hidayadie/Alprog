#!/bin/bash

# $# dipake buat ngitung jumlah
# parameter yang masuk, terus
# dicek ama if kalo ga sama
# dengan 2, dikasi eror trus exit
if [ $# -ne 2 ]
then
    echo "Penggunaan: salin.sh file-asal file-tujuan"
    exit -1
fi

# Variabel buat nyimpen nama file
# asal dan tujuannya, $1 $2 itu
# dari parameter yang dikasi pas
# manggil fungsinya
Asal=$1
Tujuan=$2

# Meriksa file asalnya ada ato ga
# kalo ga ada kasi eror trus exit
if [ ! -f "$Asal" ];
then
	echo "Salin gagal: File asal tidak ada."
	exit -1
fi

# Meriksa file tujuan -e dipake buat
# meriksa tersedia ato ga
if [ -e "$Tujuan" ]
then
# Cek file tujuannya itu direktori bukan
# kalo iya, eror trus exit
	if [ -d "$Tujuan" ]
	then
		echo "Salin gagal: File tidak bisa disalin ke direktori."
        	exit -1

	elif [ -f "$Tujuan" ]
	then
        	read -p "File tujuan sudah ada. Apakah Anda ingin menghapusnya? (Y/N): " jawab
        	if [ "$jawab" = "Y" ] || [ "$jawab" = "y" ]
		then
            		cp "$Asal" "$Tujuan"
            		echo "File berhasil disalin."
        	else
            		echo "Salin dibatalkan."
        	fi
    	else
        	echo "Salin gagal: Target bukan file biasa."
        exit -1
    fi
else
    cp "$Asal" "$Tujuan"
    echo "File berhasil disalin."
fi
