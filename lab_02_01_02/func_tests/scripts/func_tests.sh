#!/bin/bash

count_errors=0

files="../data/pos_??_in.txt"
for file_in in $files; do

	number=$(echo "$file_in" | grep -o "[0-9]*")

	if [ -z "$number" ]; then
		break
	fi

	file_out="../data/pos_""$number""_out.txt"

	if [ -f "$file_out" ]; then
		command="./pos_case.sh ""$file_in ""$file_out"
	else
		exit 100
	fi

	if $command; then
		echo -e "POS_""$number"": PASS"
	else
		echo -e "POS_""$number"": FAIL"
		count_errors=$((count_errors + 1))
	fi
done

files="../data/neg_??_in.txt"
for file_in in $files; do

	number=$(echo "$file_in" | grep -o "[0-9]*")

	if [ -z "$number" ]; then
		break
	fi

	command="./neg_case.sh ""$file_in"

	if $command; then
		echo -e "NEG_""$number"": PASS"
	else
		echo -e "NEG_""$number"": FAIL"
		count_errors=$((count_errors + 1))
	fi
done

if [ "$count_errors" -eq 0 ]; then
	echo "All tests passed." 
else
	echo "Failed $count_errors tests." 
fi

exit "$count_errors"
