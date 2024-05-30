#!/bin/bash
# program AND dan OR

# mengecek And jika ekpresi 1 ada
[ -f percobaan8.sh ] && echo "Program 8 ada"

# mengecek AND jika ekpresi 1 false
[ -f percobaan100.sh ] && echo "Program 100 ada"

# mengecek OR jika ekpresi 1 true
[ -f percobaan8.sh ] || echo "Dieksekusi tidak jika true?"

# mengecek OR jika ekpresi 1 false
[ -f percobaan100.sh ] || echo "Dieksekusi tidak jika false?"
