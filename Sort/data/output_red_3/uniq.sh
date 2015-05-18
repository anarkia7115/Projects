#!/bin/bash

for i in {0..2}
do
	echo "$i:"
	cat ./part-0000$i | awk '{print $1, $2}' | uniq
done
