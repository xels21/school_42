#!/bin/sh
# Test script for rotone
./build.sh

set -e

dir="$(dirname "$0")"
cd "$dir"

# Build
if [ -f build.sh ]; then
    sh build.sh
else
    clang rotone.c -o rotone
fi

pass=0
fail=0

test_case() {
    input="$1"
    expected="$2"
    output=$(./rotone $input | cat -e)
    if [ "$output" = "$expected" ]; then
        echo "[PASS] ./rotone $input => $output"
        pass=$((pass+1))
    else
        echo "[FAIL] ./rotone $input"
        echo "  Expected: $expected"
        echo "  Got:      $output"
        fail=$((fail+1))
    fi
}

test_case '"abc"' '"bcd"$'
test_case '"Les stagiaires du staff ne sentent pas toujours tres bon."' '"Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo."$'
test_case '"AkjhZ zLKIJz , 23y "' '"BlkiA aMLJKa , 23z "$'
test_case '' '$'
test_case '""' '""$'

echo "\nTotal: $pass passed, $fail failed."
exit $fail
