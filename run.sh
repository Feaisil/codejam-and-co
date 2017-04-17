#!/bin/sh
echo "Usage: $0 a A-small-attempt0 5"
mkdir -p out
cp ~/Downloads/$2.in in

cat in/$2.in | ./$1 > $2.out

echo '----input:'
head -n$(($3+1)) in/$2.in 
echo '----output:'
head -n$3 $2.out
