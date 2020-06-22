#!/bin/sh
[ -f "$1" ] || { echo "usage: $0 datafile.dat"; exit 1; }

output=`basename $1 .dat`.png

gnuplot <<EOF
set size ratio 1.0
set terminal png
unset key
set output "$output"
plot "$1" with circles
EOF
open $output
