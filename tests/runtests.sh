mv tests/tests.log tests/tests.log.old
touch tests/tests.log

echo "Running unit tests:"

ERRORS=0

for i in test/$TEST_PAT
do
    if test -f $i
    then
		echo "----------------------"
		echo "Running $i..."
        if $MEMTEST ./$i 2>> tests/tests.log
		then
            echo "$i passed."
        else
            echo "ERROR in $i."
			((ERRORS++))
        fi
    fi
done

echo "----------------------"


if test $ERRORS -gt 0
then
	echo -e "\t$ERRORS tests FAILED, here's tests/tests.log:"
	echo "======================================================="
	cat tests/tests.log
	echo "======================================================="
	exit 1
fi

if test -n "$MEMTEST"
then
	echo "$MEMTEST ran, here's tests/tests.log:"
	echo "======================================================="
	cat tests/tests.log
	echo "======================================================="
	exit 0
fi

echo "All tests passed! You win a hot dog!"
exit 0
