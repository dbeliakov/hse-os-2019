#!/bin/bash
set -e

gcc -Wall -Wextra -Werror $1/main.c -o $1/prog
for t in $1/tests/*; do
    if echo $t | grep -q ".*\.a"; then
        continue
    fi
    if echo $t | grep -q ".*\.out"; then
        continue
    fi
    echo Running test $t
    $1/prog < $t > $t.out
    cmp --silent $t.a $t.out
done
