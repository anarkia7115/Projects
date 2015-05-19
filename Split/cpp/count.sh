#!/bin/bash

for file in ./sample1_*.gz
do
	gunzip -dc $file |wc -l 
done
