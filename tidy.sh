#!/bin/sh
echo "Usage: $0 $1"
mkdir -p out src
mv *.out out
if diff -q $1.cc stub.ccc; then
	mv $1 src
	rm $1.cc
else
	mv $1.cc src
	rm $1
fi
git add src/$1*
