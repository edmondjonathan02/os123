#!/bin/bash

echo "Enter file name:"
read name

if [ -f $name ]
then
    echo "This is a file"
elif [ -d $name ]
then
    echo "This is a directory"
fi
