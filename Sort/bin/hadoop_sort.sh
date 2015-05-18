#!/bin/bash

hadoop fs -rm -r seq/output

hadoop jar /home/gaojiaxiang/hadoop/contrib/streaming/hadoop-streaming-2.6.0.jar \
	-D stream.num.map.output.key.fields=3 \
	-D mapred.text.key.partitioner.options=-k1,2 \
	-D mapred.job.name='hadoop sort' \
	-D mapred.reduce.tasks=3 \
	-partitioner org.apache.hadoop.mapred.lib.KeyFieldBasedPartitioner \
	-input seq/input \
	-output seq/output \
	-mapper 'cat' \
	-reducer '/home/gaojiaxiang/Projects/Sort/bin/max'

hadoop fs -get seq/output ../data/
