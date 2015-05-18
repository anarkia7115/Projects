#!/bin/bash

hadoop fs -rm -r seq/output

hadoop jar /home/gaojiaxiang/hadoop/contrib/streaming/hadoop-streaming-2.6.0.jar \
	-D mapreduce.partition.keypartitioner.options=-k2,2 \
    	-D mapreduce.fieldsel.map.output.key.value.fields.spec=0,1:0- \
	-D mapreduce.job.reduces=5 \
	-input seq/input \
	-output seq/output \
	-mapper 'cat' \
	-partitioner org.apache.hadoop.mapred.lib.KeyFieldBasedPartitioner 

hadoop fs -get seq/output ../data/output

cp ../data/uniq.sh ./output

