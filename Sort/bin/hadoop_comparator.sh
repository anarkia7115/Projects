#!/bin/bash

hadoop fs -rm -r seq/output

hadoop jar /home/gaojiaxiang/hadoop/contrib/streaming/hadoop-streaming-2.6.0.jar \
	-D mapreduce.job.output.key.comparator.class=org.apache.hadoop.mapreduce.lib.partition.KeyFieldBasedComparator \
	-D stream.num.map.output.key.fields=3 \
	-D mapreduce.job.reduces=5 \
	-D mapreduce.partition.keycomparator.options=-k2,2nr \
	-input seq/input \
	-output seq/output \
	-mapper 'cat' #&> ../data/job_log

hadoop fs -get seq/output ../data/
