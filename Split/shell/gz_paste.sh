#!/bin/bash
time paste -d'\t' <(gzip -dc ./WGC_20m_n1.fq.gz) <(gunzip -dc ./WGC_20m_n2.fq.gz) > pasted_WGC
