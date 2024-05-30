#!/bin/sh

echo -n "Jawab (y/t): "
read Jawab

case $Jawab in
y | Y | Ya | ya | YA ) Jawab=y;;
t | T | Tidak | tidak | TIDAK ) Jawab=t;;
esac
