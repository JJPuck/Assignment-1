/* ***********
* Created by Jordan Puckridge 24/08/2018
*
* Read and parse .csv input for Olympic Athlete data
*/


/* read from a file and input the data to a struct? */

#ifndef CSV_FUNC_H
#define CSV_FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

#define BUFFER_SIZE 512

/* Read data into struct using sscanf using commas, ',' as delimiter */
void read_csv_into_olympian_struct(olympian_t *target,char* temp_string);
/* Print olympian athlete data to a specified file in format described by the
*  assignment spec for COMP20003 Assignment 1 document
*/
void print_olympian(olympian_t *target, FILE* output);
/* Print olympian athlete data to a specified file in format described by the
*  assignment spec for COMP20003 Assignment 1 document
*/
olympian_t* create__entry(char* data_string);

#endif