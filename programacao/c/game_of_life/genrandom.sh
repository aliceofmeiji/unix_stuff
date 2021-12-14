#!/bin/sh

output=''

for i in `seq 1 $1`; do
	output=$(echo $output$(($(echo $RANDOM) % 2)))
done

echo $output
