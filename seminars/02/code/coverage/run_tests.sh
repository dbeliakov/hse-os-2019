#!/bin/bash

for input in `ls tests`; do
    if echo $input | grep -q -v "\.a$"; then
        ./program < tests/$input > out.tmp 2>/dev/null
        if ! cmp --silent tests/$input.a out.tmp; then
            echo "Incorrect answer in test $input"
        fi
        rm -f out.tmp
    fi
done
