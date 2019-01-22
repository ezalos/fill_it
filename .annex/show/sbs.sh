#!/bin/sh

awk '/binaries/{c++;if(c==2){ print "\t\t\tprint_soltion_link_debug(head, deepness, find_sol(head, deepness)->current_path);"; c=0 }} 1' fill_it_files/solve.c >> fill_it_files/test.c
rm fill_it_files/solve.c
cat fill_it_files/test.c >> fill_it_files/solve.c
rm fill_it_files/test.c
