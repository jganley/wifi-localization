# WiFi Localization

Built in C and Python. Our program utilizes MacOS wireless connection tools to scan wifi access points and compare a users wireless profile to a database of previously collected location based profiles. Based on this analysis, we are able to accurately guess a user's location.

## Included Files

The four included files are list.c, genHistory.sh, genTest.sh, and findloc.py.

### list.c

This program is written in C. It will *only* work on a macOS operating system as it relies on the `airport -s` program native to Mac computers. This airport program scans all nearby wireless network access points and then lists their service set identifier (SSID), basic service set identifier (BSSID), and received signal strength indicator (RSSI) value among other wireless information. The program parses this information to output the SSID, BSSID, and RSSI of each access point associated with a UCLA wireless network.

### genHistory.sh

This program is written in bash. It runs the `list` executable and then parses the output for all the BSSID values. After parsing the output, it adds the BSSID values to a csv file. Each row of the CSV file describes one location. The first value is the name of the location and each additional value is a BSSID that appears at that location.

### genTest.sh

### findloc.py

## How To Run

First, we have to generate some historical data for the python script to compare scans against.

```
./genHistory.sh [name_of_location]
```



