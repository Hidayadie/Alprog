#!/bin/bash
# 1 notasi test
i=5
test "$i" -eq 5
echo $?
echo "-------menggunakan notasi-----"
# 2 operator notasi []
[ "$i" -eq 5 ]
echo $?
