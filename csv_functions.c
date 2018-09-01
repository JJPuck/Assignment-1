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
			"%d,%[^,],%c,%d,%d,%d,%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,]",
			/* Targets */
			&target->id,        /* INT */
			target->name,      /* STRING */
			&target->sex,       /* CHAR */
			&target->age,       /* INT */
			&target->height,    /* INT */
			&target->weight,    /* INT */
			target->team_name, /* STRING */
			target->NOC,       /* STRING */
			target->games,     /* STRING */
			&target->year,      /* INT */
			target->season,    /* STRING */
			target->city,      /* STRING */
			target->sport,     /* STRING */
			target->event,     /* STRING */
			target->medal      /* STRING */
		);
}

void print_olympian(olympian_t *target){
	printf("ID: %d ",target->id);
	printf("Sex: %c || ",target->sex);
	printf("Age: %d || ",target->age);
	printf("Height: %d || ",target->height);
	printf("Weight: %d || ",target->weight);
	printf("Team: %s || ",target->team_name);
	printf("NOC: %s || ",target->NOC);
	printf("Games: %s || ",target->games);
	printf("Year: %d || ",target->year);
	printf("Season: %s || ",target->season);
	printf("City: %s || ",target->city);
	printf("Sport: %s || ",target->sport);
	printf("Event: %s || ",target->event);
	printf("Medal: %s || \n\n",target->medal);

}
