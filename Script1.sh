#!/bin/bash

echo -n "Enter three numbers : "
read num1 num2 num3

max=0

if [ $num1 -gt $num2 ]
then
	if [ $num1 -gt $num3]
	then
		echo "num1 is greater"
		max=$num1
	fi
elif [ $num2 -gt $num1]
then
	if [ $num2 -gt $num3]
	then
		echo "num2 is greater"
		max=$num2
	fi
else
	echo "num3 is greater"
	max=$num2
fi
    
echo "Maximum value = $max"

