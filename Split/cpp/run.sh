#time ./gz ./WGC_20m_n1.fq.gz ./WGC_20m_n2.fq.gz ../small_gz/WGC_Part 10000000 1
#time /home/gaojiaxiang/Projects/Split/cpp/gz ./WGC_20m_n1.fq.gz ./WGC_20m_n2.fq.gz ../small_plate/sample_out 10000000 0

#!/bin/bash

./gz -c \
  --gz1 ../gz/sample_n1.gz --gz2 '' \
  --output ../small_gz/ \
  --row 1000 \
  --callid application1 

