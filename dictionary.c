/* ***************************
* Created by Jordan Puckridge 27/8/2018
*
* Implementation of a binary search tree, insert, traverse and delete, search
* functions.
* Duplicate keys are handled by creating a new node to node->left
*
*/
#define STR_VALUE 0

#include "dictionary.h"
#include "csv_functions.h"


/* Create an empty instance of a tree */
bt_node_t* bst_make_tree(){
	return NULL;
}

/* Recursivelt insert a new element into the binary bst_search tree
* Duplicates are handled by <= and creating a new node left of the original
* Returns a pointer to the node created
*/
bt_node_t* bst_insert(bt_node_t *root, olympian_t* key){
	/* If NULL, create a new node, populate it with data*/
	if (root == NULL){
		root = malloc(sizeof(bt_node_t));
		root->left = NULL;
		root->right = NULL;
		strcpy(root->key,key->name);
		root->data = key;
		return root;
	}
	/* Move to the left if key <= the node's value */
	else if (strcmp(root->key, key->name) <=STR_VALUE){
		root->left = bst_insert(root->left, key);
	}
	/* Move right otherwise */
	else if (strcmp(root->key, key->name) > STR_VALUE){
		root->right = bst_insert(root->right, key);
	}
	return root;
}

/* Recursively search the tree for a value, continue searching until leaf
*  node is reached
*/
bt_node_t* bst_search(bt_node_t *root, string_t value, int* comparison_count, FILE* output){
	/* Checks if the node is NULL and then prints out that the value was not found
	* and returns NULL
	*/
	if(root == NULL){
		fprintf(output,"%s --> NOTFOUND\n\n",value);
		printf("%s --> %d\n",value,*comparison_count);
		return NULL;
	}
	/* NULL checks aren't costly so the comparison count is iterated after the
	* NULL check */
	(*comparison_count)++;
	/* If the value is found, print it out */
	if(strcmp(root->key,value) == STR_VALUE){
		print_olympian(root->data,output);
		printf("%s --> %d\n",value,*comparison_count);
		/* Check if the next key to the left is also a match and move left to print
		* those values if true. Otherwise return the node and end execution */
		if(root->left != NULL && strcmp(root->left->key,root->key)==STR_VALUE){
			return bst_search(root->left,value,comparison_count,output);
		}
		else return root;

	}
	/* Move left or right based on key comparison values */
	else if(strcmp(root->key, value) < STR_VALUE){
		return bst_search(root->left,value,comparison_count,output);
		}
	else {
		return bst_search(root->right,value,comparison_count,output);
	}

}

/*  traverse through the binary bst_search tree and free memory*/
bt_node_t* traverse_and_free(bt_node_t *root){
	return NULL;
}
