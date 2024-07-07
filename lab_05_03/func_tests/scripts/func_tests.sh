#!/bin/bash

pos_tests="../data/pos_*_in.txt"
neg_tests="../data/neg_*_in.txt"
pos_number=1
neg_number=1
count_errors=0

for pos_data in $pos_tests; do
	if ./pos_case.sh "$pos_data" "${pos_data/"in"/"out"}" "${pos_data/"in"/"args"}"; then
		echo "POS_$pos_number: PASS"
	else
		echo "POS_$pos_number: FAIL"
		count_errors=$((count_errors + 1))
	fi
	pos_number=$((pos_number + 1))
done


for neg_data in $neg_tests; do
	if ./neg_case.sh "$neg_data" "${neg_data/"in"/"args"}"; then
		echo "NEG_$neg_number: PASS"
	else
		echo "NEG_$neg_number: FAIL"
		count_errors=$((count_errors + 1))
	fi
	neg_number=$((neg_number + 1))

done


if [ "$count_errors" -eq 0 ]; then
	echo "All tests passed."
else
	echo "Failed $count_errors tests."
fi

exit "$count_errors"
