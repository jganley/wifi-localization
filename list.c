#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int print_arg = 0;
int is_eduroam = 0;
int is_UCLA_WIFI = 0;
int is_UCLA_WEB = 0;
int is_UCLA_WIFI_RES = 0;
int is_UCLA_WEB_RES = 0;
int is_UCLA_SECURE_RES = 0;

int print_arg_function() {

  system("rm -rf my_file.txt > emptyfile.txt");
  system("touch my_file.txt");
  //system("/System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport -s | awk '{print $1}' | sort -u > my_file.txt");
  int counter = 0;
  while (counter == 0) {
    system("/System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport -s | awk '{print $1}' | sort -u > my_file.txt");
    FILE* file8 = fopen("my_file.txt", "r");
    char line8[1024];
    while (fgets(line8, sizeof(line8), file8)) {
      ++counter;
    }
  }

  //>>>>>>> a6a4338628a778d47b35af82e41d4e36c43b43d3
  FILE* file = fopen("my_file.txt", "r");
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    if (strcmp(line,"\n")==0 || strstr(line,"1")) {
      continue;
    }
    else{
      printf("%s",line);
    }
/* if (strstr(line, "UCLA_WEB ")) {
      is_UCLA_WEB = 1;
    }
    else if (strstr(line, "UCLA_WIFI_RES ")) {
      is_UCLA_WIFI_RES = 1;
    }
    else if (strstr(line, "UCLA_WEB_RES ")) {
      is_UCLA_WEB_RES = 1;
    }
    else if (strstr(line, "UCLA_SECURE_RES ")) {
      is_UCLA_SECURE_RES = 1;
    }
    else if (strstr(line, "eduroam ")) {
      is_eduroam = 1;
      }*/
  }
  /*
  if (is_eduroam) {
    printf("eduroam\n");
  }
  if (is_UCLA_WIFI) {
    printf("UCLA_WIFI\n");
  }
  if (is_UCLA_WEB) {
    printf("UCLA_WEB\n");
  }
  if (is_UCLA_WIFI_RES) {
    printf("UCLA_WIFI_RES\n");
  }
  if (is_UCLA_WEB_RES) {
    printf("UCLA_WEB_RES\n");
  }
  if (is_UCLA_SECURE_RES) {
    printf("UCLA_SECURE_RES\n");
    }*/

  fclose(file);
  return 0;
}

int no_arg_function() {
  system("rm -rf my_file1.txt > emptyfile.txt");
  system("touch my_file1.txt");
  int counter = 0;
  while (counter == 0) {
    system("/System/Library/PrivateFrameworks/Apple80211.framework/Versions/Current/Resources/airport -s > my_file1.txt");
    FILE* file8 = fopen("my_file1.txt", "r");
    char line8[1024];
    while (fgets(line8, sizeof(line8), file8)) {
      ++counter;
    }
  }

  FILE* file = fopen("my_file1.txt", "r");
  char line[1024];
  while (fgets(line, sizeof(line), file)) {
    if (strstr(line, "UCLA")) {
      printf("%s", line);
    }
    else if (strstr(line, "eduroam")) {
      printf("%s", line);
    }
  }
  fclose(file);
  return 0;
}

int main (int argc, char **argv) {
  static struct option options_l[] = {
  {"networks", no_argument, 0, 'n'},
  {0, 0, 0, 0}
  };

  // parse through the arguments

  int c = getopt_long(argc, argv, "", options_l, NULL);
  while (c != -1) {
     switch (c) {
       case 'n':
        print_arg = 1;
        break;
       default:
        exit(1);
        break;
     }
  c = getopt_long(argc, argv, "", options_l, NULL);
  }

  if (print_arg) {
    print_arg_function();
  }
  else {
    no_arg_function();
  }
}
