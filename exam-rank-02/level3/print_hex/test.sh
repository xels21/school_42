#!/bin/sh
./build.sh

test_case() {
  expected="$2"
  output=$(./print_hex $1 | cat -e)
  if [ "$output" = "$expected" ]; then
    echo "PASS: ./print_hex $1 - got $output, expected $expected"
  else
    echo "FAIL: ./print_hex $1 - got $output, expected $expected"
    echo "  Expected: $expected"
    echo "  Got:      $output"
    fail=1
  fi
}

test_case 10 "a$"
test_case 255 "ff$"
test_case 5156454 "4eae66$"
output=$(./print_hex | cat -e)
if [ "$output" = "$" ]; then
  echo "PASS: ./print_hex (no arg)"
else
  echo "FAIL: ./print_hex (no arg)"
  echo "  Expected: $"
  echo "  Got:      $output"
  fail=1
fi

exit $fail