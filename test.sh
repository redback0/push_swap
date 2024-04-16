#!/bin/bash

INSTRS=$(./push_swap "$@")

echo "$INSTRS" | wc -l
echo "$INSTRS" | ./checker_linux "$@"
