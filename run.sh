#!/bin/sh
echo "Usage: $0 b A-small-attempt0"
mkdir -p out
cp ~/Downloads/$2.in in

cat in/$2.in | ./$1 > $2.out
