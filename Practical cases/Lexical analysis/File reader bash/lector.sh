#!/bin/bash

# Printting the file line by line
while IFS= read -r line
do
	echo "$line"
done < text.txt

# Printing the total of lines
echo "Total lines: "
cat text.txt | wc -l

# Printing the blank lines
echo "Blank lines: "
cat text.txt | grep -o '\n' | wc -l
