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

usage()
{
	echo "Usage: ./test.sh SIZE [-divn] [[-s SEED] | [-r RUNS]]"
}

check_norm()
{
	printf "Norm: "
	norm="$(norminette)"
	if [ $? -eq 1 ]; then
		printf "${RED}KO${NC}\n"
		printf "${norm}\n\n"
	else
		printf "${GREEN}OK${NC}\n\n"
	fi
}

get_seeds()
{
	printf "${YELLOW}Getting seeds...${NC}"
	seeds=($(awk -v loop=$1 -v range=$((2147483647)) 'BEGIN \
	{
		srand()
		do
		{
			numb = 1 + int(rand() * range)
			if (!(numb in prev))
			{
				print numb
				prev[numb] = 1
				count++
			}
		} while (count<loop)
	}'))
	printf " Done\n"
}

get_stack()
{
	stack=$(awk -v loop=$1 -v range=$(($1 * 20)) \
		-v take=$(($1 * 10)) -v seed=$2 'BEGIN \
		{
			srand(seed)
			do
			{
				numb = 1 + int(rand() * range - take)
				if (!(numb in prev))
				{
					print numb
					prev[numb] = 1
					count++
				}
			} while (count < loop)
		}')

	# write stack to stack.txt if -s is specified
	if [ $pstack == 1 ]; then
		echo "$stack" > stack.txt
	fi

	echo "$stack"
}

check_solution()
{
	# check if sorted correctly
	if [[ $1 == "" ]]; then
		# I should add a check here for if the stack isn't sorted
		echo "SOLVED LIST"
	else
		wcs[$i]=$(echo "$1" | wc -l | tr -d ' ')
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
			result=$(echo "$1" | ./checker $2)
		elif [[ "$OSTYPE" == "darwin"* ]]; then
			result=$(echo "$1" | ./checker_Mac $2)
		elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
			result=$(echo "$1" | ./checker_linux $2)
		fi
		if [ $silent == 0 ]; then
			echo -n "RESULT: "
			if [[ "$result" == "OK" ]]; then
				printf "${GREEN}${result}${NC}\n"
			else
				printf "${RED}${result}${NC}\n"
				fails=$(( $fails + 1 ))
				exit 1
			fi
		elif [[ "$result" == "KO" ]]; then
			printf " ${RED}${result}${NC}"
			if [ ! -z $3 ]; then
				printf "SEED: $3\n"
			fi
			fails=$(( $fails + 1 ))
		fi
	fi
}

check_stack()
{
	# run push_swap and check return value
	instrs=$(./push_swap ${stack[@]})
	exitStatus=$?
	if [[ $exitStatus -eq 139 ]]; then
		printf "${RED}SEG FAULT :(${NC}\n"
		exit 1
	elif [[ $exitStatus -ne 0 ]]; then
		printf "${RED}non-zero exit status${NC}\n"
	fi
	#write instructions to instrs.txt if -i specified
	if [ $pinstr == 1 ]; then
		echo "$instrs" > instrs.txt
	fi
}

do_runs()
{
	for (( i = 0 ; i < $runs ; i++ )); do

		stack="$( get_stack $size ${seeds[$i]} )"

		if [ $silent == 0 ]; then
			printf "${YELLOW}----------RUN----------: $((i+1))${NC}\n"
			printf "SEED: ${seeds[$i]}\n"
		else
			if [ $i -gt 0 ]; then
				printf "\r"
			fi
			printf "$((i+1))"
		fi

		check_stack
	done

	check_solution "$instrs" "${stack[@]}" ${seeds[$i]}
}

single_size()
{
	local OPTIND

	size=$1
	runs=1
	pstack=0
	pinstr=0
	silent=1
	seeds=()

	if [ -z $size ]; then
		usage
		exit 1
	fi

	shift 1

	while getopts "dir:s:vn" flag; do
		case $flag in
			d) pstack=1 ;;
			i) pinstr=1 ;;
			r) runs="${OPTARG}" ;;
			s) seeds[0]="${OPTARG}" ;;
			v) silent=0 ;;
			n) check_norm ;;
			*) usage && exit 0 ;;
		esac
	done

	if [ -z ${seeds[0]} ]; then
		get_seeds ${runs};
	fi

	sum=0
	max=0
	maxseed=
	min=-1
	fails=0
	
	do_runs

	printf "\n\n${YELLOW}----FINAL RESULTS----${NC}\n"
	echo "AVERAGE INSTRUCTIONS: $((sum / runs))"
	echo "MIN INSTRUCTIONS: $min"
	echo "MAX INSTRUCTIONS: $max (seed: $maxseed)"
	if [[ $fails -gt 0 ]]; then
		printf "\nLeft ${RED}${fails}${NC}/${runs} stacks unsorted :(\n\n"
	else
		printf "\n${GREEN}All stacks sorted! :D${NC}\n\n"
	fi
}

check_error()
{
	result=$(./push_swap $1)
	exit_status="$?"
	if [[ ${exit_status} -gt 1 ]]; then
		printf "[${RED}CRASH${NC}]\n"
		exit 1
	elif [[ -z ${result} ]] || [[ "${result}" -ne "Error" ]]; then
		printf "[${RED}KO${NC}] "
	else
		printf "[${GREEN}OK${NC}] "
	fi
	sleep 0.05
}

# check for executable
if [ ! -f "push_swap" ]; then
	printf "${YELLOW}NO EXECUTABLE -- ATTEMPTING TO MAKE${NC}\n\n"
	make
	if [ ! -f "push_swap" ]; then
		printf "${RED}MAKE FAILED${NC}\n"
		exit 1
	fi
	printf "${YELLOW}SUCCESSFULLY RAN MAKE\n\n"
fi

if [ -z $1 ]; then
	check_norm

# ERROR CASES
	printf "input handling: "
	check_error asdf
	check_error 123a
	check_error 12a321
	check_error 2147483648
	check_error 3000000000
	check_error 21474836470
	check_error -2147483649
	check_error -3000000000
	check_error -21474836480

	sleep 0.2

# STACK OF 3
	printf "\n\nstack of 3: "
	0 1 2
	0 2 1
	1 0 2
	1 2 0
	2 1 0
	2 0 1

	sleep 0.2

# STACK OF 5
	printf "\n\nstack of 5: "

	sleep 0.2

# STACK OF 100
	printf "\n\n\nstack of 100 (target: 700) 100 runs:\n\n"
	single_size 100 -vr 100

	sleep 0.5

# STACK OF 500
	printf "\n\nstack of 500 (target: 5500) 100 runs:\n\n"
	single_size 500 -vr 100

else
	single_size $@
fi
