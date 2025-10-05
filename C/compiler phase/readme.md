- gcc -save-temps test.c

source code : test.c
prepocessing : gcc -E test.c -o test.i
compilation: gcc -S test.c -o test.s
assembly: gcc -c test.s -o test.o
linking: (h.o)