
dict2: csv_functions.o dictionary.o main2.c
	gcc -g -Wall -o dict2 main2.c csv_functions.o dictionary.o

dictionary.o: dictionary.c dictionary.h
	gcc -Wall -c dictionary.c

csv_functions.o: csv_functions.c csv_functions.h
	gcc -Wall -c csv_functions.c
