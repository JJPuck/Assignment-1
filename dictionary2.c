/* ***************************
* Created by Jordan Puckridge 27/8/2018
*
* Implementation of a binary search tree insert, search, traverse and delete
* functions.
*
* Duplicates are handled by creating a linked list branching off the node
*/
#define STR_VALUE 0

#include "dictionary.h"
#include "csv_functions.h"


/* Create an empty instance of a tree */
bt_node_t* bst_make_tree(){
	return NULL;
}

/* Recursivley insert a node into a tree structure, duplicates are added into
* a linked list pointed to by the node->next pointer. Returns the pointer to the
* node when complete
*/
bt_node_t* bst_insert(bt_node_t *root, olympian_t* key){
	/* If NULL, create a new node, populate it with data*/
	if (root == NULL){
		root = malloc(sizeof(bt_node_t));
		root->left = NULL;
		root->next = NULL;
		root->right = NULL;
		strcpy(root->key,key->name);
		root->data = key;
		return root;
	}
	/* Duplicates recursivle call the function but pass the next pointer as a
	*  parameter
	*/
	else if (strcmp(root->key,key->name) == STR_VALUE){
		root->next = bst_insert(root->next, key);
	}
	/* Move left or right depending on string comparison results */
	else if (strcmp(root->key, key->name) < STR_VALUE){
		root->left = bst_insert(root->left, key);
	}
	else if (strcmp(root->key, key->name) > STR_VALUE){
		root->right = bst_insert(root->right, key);
	}
	return root;
}

/* Recursivley search for a key in bst with linked list for duplicates and
* print the number of comparisons. Data for each found node is output to a
* seperate output file */
bt_node_t* bst_search(bt_node_t *root, string_t value, int* comparison_count, FILE* output){
	/* if NULL the value does not exts, print out not found and return NULL */
	if(root == NULL){
		fprintf(output,"%s --> NOTFOUND\n\n",value);
		printf("%s --> %d\n",value,*comparison_count);
		return NULL;
	}
	/* NULL comparisons are relatively cheap in regards to performance time so
	*  the comparison count isn't iterated until after the check is performed
	 */
	(*comparison_count)++;
	/* if the key value is found, print out the data and comparisons */
	if(strcmp(root->key,value) == STR_VALUE){
		print_olympian(root->data,output);
		printf("%s --> %d\n",value,*comparison_count);
		/* if a duplicate exists, recursively call the search on it to progress
		*  across the linked list. Otherwise return */
		if(root->next != NULL){
			return bst_search(root->next,value,comparison_count,output);
		}
		else return root;
	}
	/* Move left or right based on string comparison result */
	else if(strcmp(root->key, value) < STR_VALUE){
		return bst_search(root->left,value,comparison_count,output);
		}
	else {
		return bst_search(root->right,value,comparison_count,output);
	}
}
/*  traverse through the binary search tree and free memort*/
void traverse_and_free(bt_node_t *root){
	if(root == NULL){
		return;
	}
	traverse_and_free(root->left);
	traverse_and_free(root->right);
	free(root->data);
	free(root);
}
