#!/bin/bash

# Memeriksa apakah jumlah parameter yang diberikan adalah 1
if [ $# -ne 1 ]
then
	echo "Penggunaan: checkdir.sh NamaDirektori"
	exit -1
fi

Dir=$1

# Memeriksa apakah parameter adalah direktori, jika ya, jalankan ls -ld
[ -d "$Dir" ] && ls -ld "$Dir" || echo "$Dir bukan direktori atau tidak ada."
