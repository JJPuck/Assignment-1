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
	printf("%d,%s,%c,%d,%d,%d,%s,%s,%s,%d,%s,%s,%s,%s,%s",
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
