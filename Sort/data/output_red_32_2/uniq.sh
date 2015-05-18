#!/bin/bash

for i in {01..31}
do
	echo "$i:"
	cat ./part-000$i | awk '{print $1, $2}' | uniq
done
