/* ***********
* Created by Jordan Puckridge 24/08/2018
*
* Read and parse .csv input for Olympic Athlete data and store in an olympian
* struct.
* Print out athlete data in desired format
*/
#include "csv_functions.h"
#include "dictionary.h"

/* Creates a new olympian struct, allocates the neccesary memory and returns a
*  pointer to the struct after populating it with data.
*/
olympian_t* create__entry(char* data_string){
	olympian_t *new_entry = malloc(sizeof(olympian_t));
	read_csv_into_olympian_struct(new_entry,data_string);
	return new_entry;
}
/* Read data into struct using sscanf using commas, ',' as delimiter */
void read_csv_into_olympian_struct(olympian_t *target, char* temp_string){

	sscanf(
			/* String to read */
			temp_string,
			/* Format */
			"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",

			/* Targets */
			target->id,
			target->name,
			target->sex,
			target->age,
			target->height,
			target->weight,
			target->team_name,
			target->NOC,
			target->games,
			target->year,
			target->season,
			target->city,
			target->sport,
			target->event,
			target->medal
		);
}

/* Print olympian athlete data to a specified file in format described by the
*  assignment spec for COMP20003 Assignment 1 document
*/
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
	fprintf(output,"Medal: %s || \n",target->medal);

}
