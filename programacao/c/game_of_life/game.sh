#!/bin/sh

field=$(cat field)

while [ 1 ]; do
	printf '=%.0s' `seq 1 $1`
	echo
	echo $field | tr ' ' '\n' | sed 's/0/  /g; s/1/██/g;'
	field=$(echo $field | ./gl $1 $2 $3 $4)
	#sleep 0.1
done
