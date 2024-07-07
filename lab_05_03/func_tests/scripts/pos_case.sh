#!/bin/bash

if [ $# -ne 3 ]; then
	exit 1
fi

text_file="$1"
bin_file="${1/.txt/.bin}"
out="../data/out.txt"
command="../../app.exe"

read -ra commands <<< "$(cat "$3")"

for ((i=0; i<${#commands[@]}; i++)) do
	commands[i]="${commands[i]/"./func_tests/data"/"../data"}"
done


if [ "${commands[0]}" = "s" ]; then

	$command "import" "$text_file" "$bin_file"
	$command "${commands[@]}" || exit 1
	$command "export" "$bin_file" "$out"

elif [ "${commands[0]}" = "p" ]; then

  $command "import" "$text_file" "$bin_file"
	$command "${commands[@]}" > "$out" || exit 1

else
	exit 1
fi


if ./comparator.sh "$out" "$2"; then
	exit 0
else
	exit 1
fi

