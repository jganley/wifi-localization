#!/usr/bin/python

import sys, string

class location_struct:
    def __init__(self, line):
        self.linesplit = line.rstrip('\n').split(',')
        self.name = self.linesplit[0]
        self.count = 0
        self.ap = self.linesplit[1:]

class test_struct:
    def __init__(self, line):
        self.linesplit = line.rstrip('\n').split(',')
        self.name = self.linesplit[0]
        self.guess = ""
        self.ap = self.linesplit[0:]

def load_test_csv(the_file):
    # global variables from struct
    global test_data

    # set the global variables
    test_data = 0

    # parse through the_file. It should only have one line
    for count, line in enumerate(the_file, 1):
        if count == 1:
            test_data = test_struct(line)
        else:
            sys.stderr.write("error with the test file!\nthe test file should only have one line\n")
            sys.exit(1)

def load_historical_csv():
    # open the historical_data file
    the_file = open("historical_data.csv", 'r')
    if not the_file:
        sys.stderr.write("error with the historical file!\nfile could not be opened\n")
        sys.exit(1)

    # global variables
    global historical_data

    # set the global variables
    historical_data = []

    # parse through the historical_data.csv file
    for line in the_file:
        historical_data.append(location_struct(line))

def calculate_winner():
    # global variables
    global matchAp

    # set up the global variables
    matchAp = []

    # parse through the ap addresses in the test_data
    for testAp in test_data.ap:

        # parse through the structs in the historical_data
        for historicalEntry in historical_data:
            if testAp in historicalEntry.ap:
                historicalEntry.count += 1

    # determine the winner
    winnerIndex = -1
    maxCount = 0
    for count, historicalEntry in enumerate(historical_data):
        if historicalEntry.count > maxCount:
            maxCount = historicalEntry.count
            winnerIndex = count

    # no winner was found
    if winnerIndex == -1:
        return "None of the scanned access points were a match.\nLocation could not be determined.\n"
        sys.exit(1)

    # collect the matching ap addresses
    for testAp in test_data.ap:
        if testAp in historical_data[winnerIndex].ap:
            matchAp.append(testAp)

    # return the string of the location
    return str(historical_data[winnerIndex].name)

def main():
    # check the number of arguments
    if len(sys.argv) != 2:
        sys.stderr.write("wrong number of operands\n")
        sys.exit(1)

    # open the test file for processing
    the_file = open(sys.argv[1], 'r')
    if not the_file:
        sys.stderr.write("error with the file!\nusage: python findloc the_file\n")
        sys.exit(1)

    # take the csv file and store all the information in data structures
    load_test_csv(the_file)

    # take the historical data csv and put it into the data structures
    load_historical_csv()

    # parse through the test data and add to count to figure out winner
    location = calculate_winner()

    # print out how many matches there were
    sys.stdout.write("{} Matches Were Found In This Location\n\n".format(int(len(matchAp))))

    # print out all the matching access points
    for count, match in enumerate(matchAp, 1):
        if count < 10:
            sys.stdout.write("Access Point 0{}:  {}\n".format(count, match))
        else:
            sys.stdout.write("Access Point {}:  {}\n".format(count, match))

    # print the winning location
    sys.stdout.write("\nYour location is: {}\n".format(str(location).replace("_", " ")))

if __name__ == "__main__":
    main()
