/* ***************************
* Created by Jordan Puckridge 27/8/2018
*
* Header file and function prototypes for implementation of dictionary
* using binary search tree.
*
*/
#include "dictionary.h"
#include "csv_functions.h"


/* Create an empty instance of a tree */
bt_node_t* bst_make_tree(){
	return NULL;
}

/* insert a node with equal key value into a linked list within tree */
bt_node_t* bst_insert(bt_node_t *root, olympian_t* key){
	if (root == NULL){
		root = malloc(sizeof(bt_node_t));
		root->left = NULL;
		root->right = NULL;
		strcpy(root->key,key->name);
		root->data = key;
		return root;
	}
	else if (strcmp(root->key,key->name) == 0){
		/*Create a linked list pointing to the next node */
		root->next = bst_insert(root->next, key);
	}
	else if (strcmp(root->key, key->name) <0){
		root->left = bst_insert(root->left, key);
	}
	else if (strcmp(root->key, key->name) > 0){
		root->right = bst_insert(root->right, key);
	}
	return root;
}

/* Search for a key in bst with linked list for duplicates */
bt_node_t* bst_search(bt_node_t *root, string_t value, int* comparison_count, FILE* output){
	if(root == NULL){
		fprintf(output,"%s --> NOTFOUND\n\n",value);
		printf("%s --> %d\n",value,*comparison_count);
		return NULL;
	}
	(*comparison_count)++;
	if(strcmp(root->key,value) == 0){
		print_olympian(root->data,output);
		printf("%s --> %d\n",value,*comparison_count);
		if(root->next != NULL){
			return bst_search(root->next,value,comparison_count,output);
		}
		else return root;
	}
	else if(strcmp(root->key, value) < 0){

		return bst_search(root->left,value,comparison_count,output);
		}
	else {

		return bst_search(root->right,value,comparison_count,output);
	}
}
/*  traverse through the binary search tree*/
bt_node_t* traverse(bt_node_t *root){
	return NULL;
}
