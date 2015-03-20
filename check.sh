#!/bin/bash

EXEC=tema1
TOTAL=0

for i in $(seq 1 10); do
	./$EXEC "tests/test$i.in" > "student/test$i.out"
	diff -wiB "refs/test$i.out" "student/test$i.out" > diffs
	
	echo -n "Test $i"
	if [ $? != 0 ]; then
		cat diffs | head -n 20

		echo -e "\nFile truncated!                       ... test failed!\n"

	else
		echo "                                 ... OK!"
		TOTAL=$(expr $TOTAL + 8)
	fi
done

echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo "TOTAL: $TOTAL/80 puncte"

rm -f diffs student/test*
