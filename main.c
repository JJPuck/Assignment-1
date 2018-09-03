/* Created by Jordan Puckridge 24/08/2018
*	Implementation of a bonary search tree for Olympian dataset provided
* from Kaggle. Parses the csv data into seperate structs for each entry
* and populates a bst using the name of each athlete as key.

* Performs a search for specified keys from input and returns the number of
* comparisons to find the key as well as the total amount of comparisons
* performed to find all keys.

* Prints the number of comparisons to stdout and the information of each
* athlete to a seperate output file.

* To run the program:
* $ program_name input_file.csv output.file < keys_be_searched.file
*/


#include "csv_functions.h"
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>

#define SINGLE_CHARACTER 1
#define COUNT_START 0
#define FIRST_FILE_ARG 1
#define SECOND_FILE_ARG 2

int main(int argc, char const *argv[]) {

	FILE * csv_file;
	FILE * output;
	csv_file = fopen(argv[FIRST_FILE_ARG],"r");
	output = fopen(argv[SECOND_FILE_ARG],"w");
	int str_len;
	int comparison_count = COUNT_START;
	int total_comparisons = COUNT_START;
	char read_string[BUFFER_SIZE];
	bt_node_t* tree = bst_make_tree();
	olympian_t *temp_olymp;

	/* Stores the olympian data in a temporary struct then inserts it into
	*  the tree structure using the athlete name as key. Loops until the
	*  file is empty.
	*/
	while(fgets(read_string,BUFFER_SIZE,csv_file) != NULL){
		temp_olymp = create__entry(read_string);
		tree = bst_insert(tree,temp_olymp);
	}
	fclose(csv_file);

	/* Loop through a file of keys and search the tree for them
	*  Outputs the number of comparisons needed to find each node.
	* Outputs the athlete data to output file
	*/
	while(fgets(read_string,BUFFER_SIZE,stdin) != NULL)
	{
		/* Remove the trailing \n character introduced by fgets()
		*  Ignores single characters
		*/
		str_len = strlen(read_string);
		if(str_len > SINGLE_CHARACTER){
			read_string[str_len-1] = 0;
		}
		comparison_count = COUNT_START;
		bst_search(tree,read_string,&comparison_count,output);
		total_comparisons = total_comparisons + comparison_count;
	}
	fclose(output);
	traverse_and_free(tree);
  return 0;
}