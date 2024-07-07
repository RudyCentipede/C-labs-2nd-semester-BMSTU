#!/bin/bash

if [ $# -ne 3 ]; then
	exit 1
fi

bin_file="${1/.txt/.bin}"
bin_dst_file="${1/.txt/_dst.bin}"
data_file_txt="${1/_in.txt/_data.txt}"
data_file="${1/_in.txt/_data.bin}"
text_file="$1"
out="../data/out.txt"
command="../../app.exe"

read -ra commands <<< "$(cat "$3")"

for ((i=0; i<${#commands[@]}; i++)) do
	commands[i]="${commands[i]/"./func_tests/data"/"../data"}"
done


if [ "${commands[0]}" = "sb" ]; then

  $command "import" "$text_file" "$bin_file"
	$command "${commands[@]}" || exit 1
	$command "export" "$bin_dst_file" "$out"

elif [ "${commands[0]}" = "ab" ]; then

  $command "import" "$data_file_txt" "$data_file"
	$command "${commands[@]}" < "$text_file" || exit 1
	$command "export" "$data_file" "$out"

elif [ "${commands[0]}" = "fb" ]; then

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

