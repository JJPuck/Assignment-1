dict1: csv_functions.o dictionary.o main.c
	gcc -g -Wall -o dict1 main.c csv_functions.o dictionary.o

dict2: csv_functions.o dictionary2.o main.c
	gcc -g -Wall -o dict2 main.c csv_functions.o dictionary2.o

dictionary2.o: dictionary2.c dictionary.h
	gcc -Wall -c dictionary2.c

dictionary.o: dictionary.c dictionary.h
	gcc -Wall -c dictionary.c

csv_functions.o: csv_functions.c csv_functions.h
	gcc -Wall -c csv_functions.c
