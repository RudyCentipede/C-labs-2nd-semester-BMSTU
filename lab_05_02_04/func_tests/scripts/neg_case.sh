#!/bin/bash

if [ $# -lt 1 ]; then
	exit 1
fi

in_test=$1
out_prog="out.txt"
command="../../app.exe"

if $command "$in_test" > "$out_prog"; then
	exit 1
else
	exit 0
fi