#include "csv_functions.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {

	FILE * csv_file;
	FILE * output;
	csv_file = fopen(argv[1],"r");
	output = fopen(argv[2],"w");


	int comparison_count = 0;
	int total_comparisons = 0;
	char temp_string[BUFFER_SIZE];
	bt_node_t* tree = bst_make_tree();
	olympian_t *temp_olymp;


	while(fgets(temp_string,BUFFER_SIZE,csv_file) != NULL){
		temp_olymp = create__entry(temp_string);
		tree = bst_insert(tree,temp_olymp);
	}
	fclose(csv_file);

	while(fgets(temp_string,BUFFER_SIZE,stdin) != NULL)
	{
		temp_string[strlen(temp_string)-1] = '\0';
		comparison_count = 0;
		search(tree,temp_string,&comparison_count,output);
		total_comparisons = total_comparisons + comparison_count;
	}


printf("Total Comparisons: %d",total_comparisons);

/* TO DO
* Write the output format print function
* write the count function
* output to a file
* reimplement stage 2
* Write report on complextiy
*/
  return 0;
}
