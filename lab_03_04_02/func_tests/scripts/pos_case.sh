#!/bin/bash

if [ $# -lt 2 ]; then
	exit 1
fi

in_test=$1
out_test=$2
out_prog="out.txt"
command="../../app.exe"

if ! $command < "$in_test" > "$out_prog"; then
	exit 1
fi

if ! ./comparator.sh "$out_prog" "$out_test"; then
	exit 1
else
	exit 0
fi