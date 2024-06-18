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
		local arr=($2)
		for (( i = 0 ; i < ${#arr[@]} - 1 ; i++ )); do
			if [[ ${arr[$i]} -gt ${arr[$(( i + 1 ))]} ]]; then
				printf "${RED}KO${NC}\n"
				fails=$(( $fails + 1 ))
				return
			fi
		done
		if [[ $silent == 0 ]]; then
			printf "${GREEN}KO${NC}\n"
		fi
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
		if [[ $silent == 0 ]]; then
			echo -n "TOTAL INSTRUCTIONS: "
			echo ${wcs[$i]}
		fi
		if [ -f "checker" ]; then
			result=$(echo "$1" | ./checker $2)
		elif [[ "$OSTYPE" == "darwin"* ]]; then
			result=$(echo "$1" | ./checker_Mac $2)
		elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
			result=$(echo "$1" | ./checker_linux $2)
		fi
		solved=1
		if [[ $silent == 0 ]]; then
			echo -n "RESULT: "
			if [[ "$result" == "OK" ]]; then
				printf "${GREEN}${result}${NC}\n"
			else
				printf "${RED}${result}${NC}\n"
				fails=$(( $fails + 1 ))
				exit 1
			fi
		elif [[ "$result" -ne "OK" ]]; then
			printf " ${RED}${result}${NC}"
			solved=0
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
	instrs=$(./push_swap $1)
	exitStatus=$?
	if [[ $exitStatus -eq 139 ]]; then
		printf "${RED}SEG FAULT :(${NC}\n"
		exit 1
	elif [[ $exitStatus -ne 0 ]]; then
		printf "${RED}non-zero exit status${NC}\n"
	fi
	#write instructions to instrs.txt if -i specified
	if [[ $pinstr -eq 1 ]]; then
		echo "$instrs" > instrs.txt
	fi

	check_solution "$instrs" "${stack[@]}" ${seeds[$i]}
}

do_runs()
{
	for (( i = 0 ; i < $runs ; i++ )); do

		stack="$( get_stack $size ${seeds[$i]} )"

		if [[ $silent -eq 0 ]]; then
			printf "${YELLOW}----------RUN----------: $((i+1))${NC}\n"
			printf "SEED: ${seeds[$i]}\n"
		else
			if [ $i -gt 0 ]; then
				printf "\r"
			fi
			printf "$((i+1))"
		fi

		check_stack "${stack[@]}"

	done

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

	do_runs

	printf "\n\n${YELLOW}----RESULTS----${NC}\n"
	echo "AVERAGE INSTRUCTIONS: $((sum / runs))"
	echo "MIN INSTRUCTIONS: $min"
	echo "MAX INSTRUCTIONS: $max (seed: $maxseed)"
}

check_error()
{
	result=$(./push_swap $1 2>&1)
	exit_status="$?"
	if [[ ${exit_status} -gt 1 ]]; then
		printf "[${RED}CRASH${NC}]\n"
		exit 1
	elif [[ -z ${result} ]] || [[ "${result}" -ne "Error" ]]; then
		printf "[${RED}KO${NC}] "
	else
		printf "[${GREEN}OK${NC}] "
	fi
}

no_return()
{
	result=$(./push_swap $1)
	exit_status="$?"
	if [[ ${exit_status} -gt 1 ]]; then
		printf "[${RED}CRASH${NC}]\n"
		exit 1
	elif [[ -z ${result} ]]; then
		printf "[${GREEN}OK${NC}] "
	else
		printf "[${RED}KO${NC}] "
	fi
}

small_stack()
{
	check_stack "$1"
	num_instr=$(echo "$instrs" | wc -l | tr -d ' ')
	if [[ $solved -gt 0 ]]; then
		if [[ ! $num_instr -gt $2 ]]; then
			printf "[${GREEN}OK${NC}] "
		else
			printf "[${RED}KO ${NC}(to many instructions)] "
		fi
	fi
}

all_stacks()
{
	local prefix=$1
	local remaining=$2
	local length=${#remaining}
	local i

	if [[ $length == 0 ]]; then
		if [[ "${prefix}" != "$3" ]]; then
			small_stack "$prefix" $4
		fi
	else
		for (( i = 0 ; i < $length ; i++ )); do
			all_stacks "${prefix}${remaining:i:1} " \
				"${remaining:0:i}${remaining:i+1}" "$3" $4
		done
	fi
}

get_score()
{
	# $1 : instructions number
	local range=$2
	local change=$3

	if [[ $1 -lt $range ]]; then
		score=5
	elif (( $1 < ( $range + $change ) )); then
		score=4
	elif (( $1 < ( $range + $change * 2 ) )); then
		score=3
	elif (( $1 < ( $range + $change * 3 ) )); then
		score=2
	elif (( $1 < ( $range + $change * 4 ) )); then
		score=1
	else
		score=0
	fi
	printf "Eval score for $4 version: ${score}/5\n"
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

fails=0

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
	check_error "4 8 1 5 8"
	check_error "1 2 3 4 5 3 6 7 8"

	printf "\n\nSolved lists: "
	no_return "0 1 2"
	no_return "-100 0 100 200"
	no_return "23 42 75 5092 12345 654321"
	no_return "$(seq -1000 10 1000)"

# STACK OF 3
	printf "\n\nstack of 3: "

	all_stacks "" "012" "0 1 2 " 3

# STACK OF 5
	printf "\n\nstack of 5: "

	all_stacks "" "01234" "0 1 2 3 4 " 12

# STACK OF 100
	printf "\n\n\nstack of 100 (target: 700) 100 runs:\n\n"

	single_size 100 -r 100

	printf "\n\n\n"
	get_score "${max}" 700 200 "middle"

# STACK OF 500
	printf "\n\nstack of 500 (target: 5500) 100 runs:\n\n"

	single_size 500 -r 100

	printf "\n\n\n"
	get_score "${max}" 5500 1500 "advanced"

	if [[ $fails -gt 0 ]]; then
		printf "\nLeft ${RED}${fails}${NC}/${runs} stacks unsorted :(\n\n"
	else
		printf "\n${GREEN}All stacks sorted! :D${NC}\n\n"
	fi

else
	single_size $@

	if [[ $fails -gt 0 ]]; then
		printf "\nLeft ${RED}${fails}${NC}/${runs} stacks unsorted :(\n\n"
	else
		printf "\n${GREEN}All stacks sorted! :D${NC}\n\n"
	fi
fi
