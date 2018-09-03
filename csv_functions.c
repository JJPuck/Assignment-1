/* ***********
* Created by Jordan Puckridge 24/08/2018
*
* Read and parse .csv input for Olympic Athlete data
*/
#include "csv_functions.h"
#include "dictionary.h"

olympian_t* create__entry(char* data_string){
	olympian_t *new_entry = malloc(sizeof(olympian_t));
	read_csv_into_olympian_struct(new_entry,data_string);
	return new_entry;
}
/* Read data into struct using sscanf */
void read_csv_into_olympian_struct(olympian_t *target, char* temp_string){
	//char temp_string[BUFFER_SIZE];
	sscanf(
			/* String to read */
			temp_string,
			/* Format */
			"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
			/* Targets */
			target->id,        /* INT */
			target->name,      /* STRING */
			target->sex,       /* CHAR */
			target->age,       /* INT */
			target->height,    /* INT */
			target->weight,    /* INT */
			target->team_name, /* STRING */
			target->NOC,       /* STRING */
			target->games,     /* STRING */
			target->year,      /* INT */
			target->season,    /* STRING */
			target->city,      /* STRING */
			target->sport,     /* STRING */
			target->event,     /* STRING */
			target->medal      /* STRING */
		);
}

void print_olympian(olympian_t *target, FILE* output){
	fprintf(output,"%s --> ",target->name);
	fprintf(output,"ID: %s ",target->id);
	fprintf(output,"Sex: %s || ",target->sex);
	fprintf(output,"Age: %s || ",target->age);
	fprintf(output,"Height: %s || ",target->height);
	fprintf(output,"Weight: %s || ",target->weight);
	fprintf(output,"Team: %s || ",target->team_name);
	fprintf(output,"NOC: %s || ",target->NOC);
	fprintf(output,"Games: %s || ",target->games);
	fprintf(output,"Year: %s || ",target->year);
	fprintf(output,"Season: %s || ",target->season);
	fprintf(output,"City: %s || ",target->city);
	fprintf(output,"Sport: %s || ",target->sport);
	fprintf(output,"Event: %s || ",target->event);
	fprintf(output,"Medal: %s || \n\n",target->medal);

}
