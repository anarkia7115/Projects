#!/bin/bash

for file in ./*
do
	echo "$file:"
	cat ./$file | awk '{print $3}' | uniq
done
