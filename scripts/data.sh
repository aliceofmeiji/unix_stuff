#!/bin/sh

while :
	do
		xsetroot -d "$DISPLAY" -name "$(amixer -c $(aplay -l | sed -n "/Generic/ p" | sed -n "/device 0/ p" | cut -d ' ' -f2 | sed "s/://") sget Master | sed -n '/%/ p' | cut -d '[' -f2 | sed 's/]//')| $(musicaatual) | $(statusmusica) | $(date)"
		sleep 1;
	done
