#!/bin/bash

if [ $# -eq 1 ]; then
#	STACK=($(shuf -i $(($1 * -10))-$(($1 * 10)) -n $1))
	STACK=$(awk -v loop=$1 -v range=$(($1 * 20)) -v take=$(($1 * 10)) 'BEGIN{
			srand()
			do {
				numb = 1 + int(rand() * range - take)
				if (!(numb in prev)) {
				print numb
				prev[numb] = 1
				count++
				}
			} while (count<loop)
			}')
	echo "--STACK--"
	echo "$STACK"
	echo "--END--"

	INSTRS=$(./push_swap ${STACK[@]})

	echo "$INSTRS" | wc -l | tr -d ' '
	echo "$INSTRS" | ./checker_Mac ${STACK[@]}
fi
