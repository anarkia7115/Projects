#less /mnt/raw_data/dengyang/fq/WGC028528D_n1.fq.gz | head -5000 - | gzip -c - > ./WGC028528D_n1.fq.gz
#less /mnt/raw_data/dengyang/fq/WGC028528D_n2.fq.gz | head -5000 - | gzip -c - > ./WGC028528D_n2.fq.gz
#less /mnt/raw_data/dengyang/fq/WGC028529D_n1.fq.gz | head -5000 - | gzip -c - > ./WGC028529D_n1.fq.gz
#less /mnt/raw_data/dengyang/fq/WGC028529D_n2.fq.gz | head -5000 - | gzip -c - > ./WGC028529D_n2.fq.gz

bwa mem /mnt/ref/hg19/hg19.fa WGC028528D_n1.fq.gz WGC028528D_n2.fq.gz > 5000lines_28.sam
bwa mem /mnt/ref/hg19/hg19.fa WGC028529D_n1.fq.gz WGC028529D_n2.fq.gz > 5000lines_29.sam
