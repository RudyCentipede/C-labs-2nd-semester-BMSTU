#!/bin/bash

if [ $# -ne 2 ]; then
	exit 1
fi

text_file="$1"
bin_file="${1/.txt/.bin}"
out="../data/out.txt"
command="../../app.exe"

read -ra commands <<< "$(cat "$2")"

for ((i=0; i<${#commands[@]}; i++)) do
	commands[i]="${commands[i]/"./func_tests/data"/"../data"}"
done

$command "import" "$text_file" "$bin_file"

if ! $command "${commands[@]}" > "$out"; then
	exit 0
else
	exit 1
fi

