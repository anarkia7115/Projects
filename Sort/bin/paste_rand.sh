#!/bin/bash

./rand 1    > ../data/d0
echo "d0 generated!"

echo "generating d1..."
sleep 2
./rand 9    > ../data/d1
echo "d1 generated!"

echo "generating d2..."
sleep 2
./rand 99   > ../data/d2
echo "d2 generated!"

echo "generating d3..."
sleep 2
./rand 999  > ../data/d3
echo "d3 generated!"

echo "generating d4..."
sleep 2
./rand 9999 > ../data/d4
echo "d4 generated!"

echo "DONE!!"

paste ../data/d* > ../data/random_data
