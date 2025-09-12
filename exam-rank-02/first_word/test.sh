#!/bin/sh
./build.sh

fail=0

test_case() {
	expected="$1"
	shift
	output=$(./first_word "$@" | cat -e)
	if [ "$output" = "$expected" ]; then
		echo "PASS: ./first_word $*"
	else
		echo "FAIL: ./first_word $*"
		echo "  Expected: $expected"
		echo "  Got:      $output"
		fail=1
	fi
}

# Test cases: expected_output, followed by arguments (one or more)
test_case "FOR$" "FOR PONY"
test_case "this$" "this        ...    is sparta, then again, maybe    not"
test_case "$" "   "
test_case "$" a b
test_case "lorem,ipsum$" "  lorem,ipsum  "

exit $fail