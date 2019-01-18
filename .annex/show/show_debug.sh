#!/bin/bash

sed -i '' '98G' fill_it_files/setup_struct.c
sed -i '' '98a\
	print_debug(head);' fill_it_files/setup_struct.c
awk '/print_pieces/{c++;if(c==2){sub("print_pieces","print_pieces_color");c=0}}1' fill_it_files/printing_the_result.c > temp.c
rm fill_it_files/printing_the_result.c
cat temp.c > fill_it_files/printing_the_result.c
rm temp.c
#sed -i '' '88G' fill_it_files/solve.c
#sed -i '' '88a\
#	print_soltion_link_debug(head, deepness, find_sol(head, deepness)->current_path);' fill_it_files/solve.c
sed -i '' '60G' .annex/printing/print_r_in_color.c
sed -i '' '60a\
	print_time(time_exe(__func__, clock()));' .annex/printing/print_r_in_color.c
sed -i '' 's/# define OFFPTION/# define ONPTION/' fill_it_files/head.h
