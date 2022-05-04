#!/bin/bash

echo "How many terms to be generated"
read n
function fib
{
    x = 0
    y = 1
    i = 2
    echo "Fibonacci series up to $n terms:"
    echo "$x"
    echo "$y"
    while [ $i -lt $n ]
    do
        i = `expr $i + 1`
        z = `expr $x + $y`
        echo "$z"
        x = $y
        y = $z
    done
}
r = `fib $n`
echo "$r"
