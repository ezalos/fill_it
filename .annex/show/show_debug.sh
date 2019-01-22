#!/bin/bash

### TO INPUT PRINT_DEBUG INTO SETUP_STRUCT ###
awk '/return/{c++;if(c==14){ print "\tprint_debug(head);"; c=0 }} 1' fill_it_files/setup_struct.c >> fill_it_files/tmp.c
rm fill_it_files/setup_struct.c
cat fill_it_files/tmp.c >> fill_it_files/setup_struct.c
rm fill_it_files/tmp.c

### TO INPUT PRINT_PIECES_COLOR INSTEAD OF PRINT_PIECES IN PRINTING_THE_RESULT ###
awk '/print_pieces/{c++;if(c==3){sub("print_pieces","print_pieces_color");c=0}}1' fill_it_files/printing_the_result.c > temp.c
rm fill_it_files/printing_the_result.c
cat temp.c > fill_it_files/printing_the_result.c
rm temp.c

### TO INPUT PRINT_TIME IN PRINT_R_IN_COLOR ###
awk '/\-1/{c++;if(c==1){ print "\tprint_time(time_exe(__func__, clock()));"; c=1 }} 1' .annex/printing/print_r_in_color.c > temp.c
rm .annex/printing/print_r_in_color.c
cat temp.c > .annex/printing/print_r_in_color.c
rm temp.c

### TO TURN OFFPTION INTO ONPTION ###
sed -i '' 's/# define OFFPTION/# define ONPTION/' fill_it_files/head.h
