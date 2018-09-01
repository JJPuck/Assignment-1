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

struct olympian{
	int id;
  string_t name;
  char sex;
  int age;
  int height;
  int weight;
  string_t team_name;
  string_t NOC;
  string_t games;
  int year;
  string_t season;
  string_t city;
  string_t sport;
  string_t event;
  string_t medal;
};

typedef struct olympian olympian_t;

struct node{
	struct node* left;
  struct node* right;
	olympian_t* data;
	string_t key;

};

typedef struct node bt_node_t;

/* Returns NULL to create a base instance of a tree  */
bt_node_t* bst_make_tree();
/* Insert a new element into the binary search tree */
bt_node_t* bst_insert(bt_node_t *root, olympian_t* key);
/* insert a node with equal key value into a linked list within tree */
bt_node_t* insert_equal_key(bt_node_t *root);
/*  traverse through the binary search tree*/
bt_node_t* traverse(bt_node_t *root);
/* Search the tree for a given key and count the number of comparisons */
bt_node_t* search(bt_node_t* root, string_t value,int* comparison_count);

#endif
