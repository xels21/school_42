#!/bin/sh
./build.sh

# Automated test for fizzbuzz (first 20 numbers)
expected_output="1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
16
17
fizz
19
buzz"

output=$(./fizz_buzz | head -20)

if [ "$output" = "$expected_output" ]; then
  echo "PASS: fizzbuzz first 20 lines"
else
  echo "FAIL: fizzbuzz first 20 lines"
  echo "Expected:"
  echo "$expected_output"
  echo "Got:"
  echo "$output"
fi