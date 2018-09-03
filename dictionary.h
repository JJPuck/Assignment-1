/* ***************************
* Created by Jordan Puckridge 20/8/2018
*
* Header file and function prototypes for implementation of dictionary
* using binary search tree.
*
*/
#ifndef DICT_H
#define DICT_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_STRING_LENGTH 128

typedef char string_t[MAX_STRING_LENGTH];

/* Struct used to contain the athlete's data after it is read from the csv
* Stored as strings to allow usage of NA as a value for fields that would
* usually take an int for double
*/
struct olympian{
	string_t id;
  string_t name;
  string_t sex;
  string_t age;
  string_t height;
  string_t weight;
  string_t team_name;
  string_t NOC;
  string_t games;
  string_t year;
  string_t season;
  string_t city;
  string_t sport;
  string_t event;
  string_t medal;
};

typedef struct olympian olympian_t;

/* Node for the bst, takes a string as key and holds an extra pointer
* 'next' for implementing linked lists to handle duplicates.
* holds a pointer to an olympian_t struct that stores the rest of the data
*/
struct node{
	struct node* left;
  struct node* right;
	struct node* next;
	olympian_t* data;
	string_t key;

};

typedef struct node bt_node_t;

/* Returns NULL to create a base instance of a tree  */
bt_node_t* bst_make_tree();
/* Insert a new element into the binary search tree */
bt_node_t* bst_insert(bt_node_t *root, olympian_t* key);
/* Search the tree for a given key and count the number of comparisons */
bt_node_t* bst_search(bt_node_t* root, string_t value,int* comparison_count, FILE* output);
/*  traverse through the binary search tree and free memory*/
void traverse_and_free(bt_node_t *root);

#endif
