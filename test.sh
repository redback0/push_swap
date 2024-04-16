#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

usage() {
	echo "Usage: ./test.sh SIZE [-si]"
}

size=$1
pstack=0
pinstr=0
shift 1

while getopts "si" flag; do
	case $flag in
		s) pstack=1 ;;
		i) pinstr=1 ;;
	esac
done

if [ -z $size ]; then
	usage
	exit 1
fi

stack=$(awk -v loop=$size -v range=$(($size * 20)) -v take=$(($size * 10)) 'BEGIN{
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

# write stack to stack.txt if -s specified
if [ $pstack == 1 ]; then
	echo "--STACK--" > stack.txt
	echo "$stack" >> stack.txt
	echo "--END--" >> stack.txt
fi

instrs=$(./push_swap ${stack[@]})

#write instructions to instrs.txt if -i specified
if [ $pinstr == 1 ]; then
	echo "--INSTRS--" > instrs.txt
	echo "$instrs" >> instrs.txt
	echo "--END--" >> instrs.txt
fi

echo -n "TOTAL INSTRUCTIONS: "
echo "$instrs" | wc -l | tr -d ' '

echo -n "RESULT: "
if [[ "$OSTYPE" == "darwin"* ]]; then
	result=$(echo "$instrs" | ./checker_Mac ${stack[@]})
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
	result=$(echo "$instrs" | ./checker_linux ${stack[@]})
fi

if [[ "$result" == "OK" ]]; then
	printf "${GREEN}${result}${NC}\n"
else
	printf "${RED}${result}${NC}\n"
fi
