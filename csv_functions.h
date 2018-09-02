/* ***********
* Created by Jordan Puckridge 24/08/2018
*
* Read and parse .csv input for Olympic Athlete data
*/


/* read from a file and input the data to a struct? */
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

#define BUFFER_SIZE 512

void read_csv_into_olympian_struct(olympian_t *target,char* temp_string);
void print_olympian(olympian_t *target, FILE* output);
olympian_t* create__entry(char* data_string);
