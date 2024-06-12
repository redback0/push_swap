#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njackson <njackson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 10:46:38 by njackson          #+#    #+#              #
#    Updated: 2024/05/12 16:38:27 by njackson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

usage() {
	echo "Usage: ./test.sh SIZE [-div] [[-s SEED] | [-r RUNS]]"
}

size=$1
runs=1
pstack=0
pinstr=0
silent=1
seeds=()
shift 1

while getopts "dir:s:v" flag; do
	case $flag in
		d) pstack=1 ;;
		i) pinstr=1 ;;
		r) runs="${OPTARG}" ;;
		s) seeds[0]="${OPTARG}" ;;
		v) silent=0 ;;
		*) usage && exit 0 ;;
	esac
done

if [ -z $size ]; then
	usage
	exit 1
fi

printf "Norm: "
norm="$(norminette)"
if [ $? -eq 1 ]; then
	printf "${RED}KO${NC}\n"
	printf "${norm}\n\n"
else
	printf "${GREEN}OK${NC}\n\n"
fi

if [ ! -f "push_swap" ]; then
	printf "${YELLOW}NO EXECUTABLE -- ATTEMPTING TO MAKE${NC}\n\n"
	make
	if [ ! -f "push_swap" ]; then
		printf "${RED}MAKE FAILED${NC}\n"
		exit 1
	fi
	printf "${YELLOW}SUCCESSFULLY RAN MAKE\n\n"
fi

if [ -z ${seeds[0]} ]; then
	printf "${YELLOW}Getting seeds...${NC}"
	seeds=($(awk -v loop=$runs -v range=$((2147483647)) 'BEGIN{
		srand()
		do {
			numb = 1 + int(rand() * range)
			if (!(numb in prev)) {
			print numb
			prev[numb] = 1
			count++
			}
		} while (count<loop)
		}'))
	printf " Done\n"
fi

sum=0
max=0
maxseed=
min=-1

for (( i = 0 ; i < $runs ; i++ )); do
	stack=$(awk -v loop=$size -v range=$(($size * 20)) -v take=$(($size * 10)) -v seed=${seeds[$i]} 'BEGIN{
		srand(seed)
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
		echo "$stack" > stack.txt
	fi

	if [ $silent == 0 ]; then
		printf "${YELLOW}----------RUN----------: $((i+1))${NC}\n"
		printf "SEED: ${seeds[$i]}\n"
	else
		if [ $i -gt 0 ]; then
			printf "\r"
		fi
		printf "$((i+1))"
	fi

	instrs=$(./push_swap ${stack[@]})
	exitStatus=$?
	if [[ $exitStatus -ne 0 ]]; then
		printf "${RED}SEG FAULT :(${NC}\n"
		exit 1
	fi
	#write instructions to instrs.txt if -i specified
	if [ $pinstr == 1 ]; then
		echo "$instrs" > instrs.txt
	fi
	if [[ $instrs == "" ]]; then
		echo "SOLVED LIST"
	else
		wcs[$i]=$(echo "$instrs" | wc -l | tr -d ' ')
		sum=$(( $sum + ${wcs[$i]} ))
		if [[ ${wcs[$i]} -lt $min ]] || [[ $min -lt 0 ]]; then
			min=${wcs[$i]}
		fi
		if [[ ${wcs[$i]} -gt $max ]]; then
			max=${wcs[$i]}
			maxseed=${seeds[$i]}
		fi
		if [ $silent == 0 ]; then
			echo -n "TOTAL INSTRUCTIONS: "
			echo ${wcs[$i]}
		fi
		if test -f "checker"; then
			result=$(echo "$instrs" | ./checker ${stack[@]})
		elif [[ "$OSTYPE" == "darwin"* ]]; then
			result=$(echo "$instrs" | ./checker_Mac ${stack[@]})
		elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
			result=$(echo "$instrs" | ./checker_linux ${stack[@]})
		fi
		if [ $silent == 0 ]; then
			echo -n "RESULT: "
			if [[ "$result" == "OK" ]]; then
				printf "${GREEN}${result}${NC}\n"
			else
				printf "${RED}${result}${NC}\n"
				exit 1
			fi
		fi
	fi
done

echo
printf "\n${YELLOW}----FINAL RESULTS----${NC}\n"
echo "AVERAGE INSTRUCTIONS: $((sum / runs))"
echo "MIN INSTRUCTIONS: $min"
echo "MAX INSTRUCTIONS: $max (seed: $maxseed)"
