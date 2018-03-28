#!/bin/sh

./list > my_file2.txt
printf "%s" $1 >> historical_data.csv
printf "%s" "," >> historical_data.csv
sort -t'-' -n -k 2 my_file2.txt | sed 's/\s\+/\n/g' | grep ..:..:..:..:..:.. | tr '\n' ',' | sed s/,$/\\n/g >>  historical_data
