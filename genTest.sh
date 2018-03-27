#!/bin/sh

./list > my_file2.txt
sort -t'-' -n -k 2 my_file2.txt | sed 's/\s\+/\n/g' | grep ..:..:..:..:..:.. | tr '\n' ',' | sed s/,$/\\n/g >  test_data.csv
