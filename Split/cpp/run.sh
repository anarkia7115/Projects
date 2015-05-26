#time ./gz ./WGC_20m_n1.fq.gz ./WGC_20m_n2.fq.gz ../small_gz/WGC_Part 10000000 1
#time /home/gaojiaxiang/Projects/Split/cpp/gz ./WGC_20m_n1.fq.gz ./WGC_20m_n2.fq.gz ../small_plate/sample_out 10000000 0

#!/bin/bash

rm ../small_plate/*

./gz \
  --gz1 ../gz/WGC_20m_n1.fq.gz --gz2 ../gz/WGC_20m_n2.fq.gz \
  --output ../small_plate/ \
  --row 1000000 \
  --callid application1 

