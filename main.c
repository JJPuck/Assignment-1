#include "csv_functions.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {

	FILE * csv_file;
	csv_file = fopen(argv[1],"r");
	//input = fopen(argv[2],"r");


	char temp_string[BUFFER_SIZE];
	bt_node_t* tree = bst_make_tree();
	olympian_t *temp_olymp;

	char* name = "olympian name";

	while(fgets(temp_string,BUFFER_SIZE,csv_file) != NULL){
		temp_olymp = create__entry(temp_string);
		tree = bst_insert(tree,temp_olymp);
	}
	fclose(csv_file);

	//search(tree,name);



/* TO DO
* Write the output format print function
* write the count function
* output to a file
* reimplement stage 2
* Write report on complextiy
*/
  return 0;
}
