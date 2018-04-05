# WiFi Localization

Built in C and Python. Our program utilizes MacOS wireless connection tools to scan wifi access points and compare a users wireless profile to a database of previously collected location based profiles. Based on this analysis, we are able to accurately guess a user's location.

## Included Files

The four included files are list.c, genHistory.sh, genTest.sh, and findloc.py.

## How To Run

### list.c

This program is written in C. It will *only* work on a macOS operating system as it relies on the `airport -s` program native to Mac computers. This airport program scans all nearby wireless network access points and then lists their service set identifier (SSID), basic service set identifier (BSSID), and received signal strength indicator (RSSI) value among other wireless information. The program parses this information to output the SSID, BSSID, and RSSI of each access point associated with a UCLA wireless network.

### genHistory.sh

### genTest.sh

### findloc.py
