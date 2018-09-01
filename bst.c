/* ***************************

* Created by Jordan Puckridge 20/8/2018
*
* Implementation of Binary Search Tree fucntions including...
* Creation of a new tree
* Inserting new items into the tree,
* Searching for an item in the tree,
*
*/

//NOTES FOR ME (DELETE)
//BINARY SEARCH TREE WITH LINKED LIST FOR DUPLICATE ITEMS
#define STRING_LENGTH 128

struct olympian{
  int id;
  char[STRING_LENGTH] name;
  char sex;
  int age;
  float height;
  float weight;
  char[STRING_LENGTH] team_name;
  char[STRING_LENGTH] NOC;
  char[STRING_LENGTH] games;
  int year;
  char[STRING_LENGTH] season;
  char[STRING_LENGTH] city;
  char[STRING_LENGTH] sport;
  char[STRING_LENGTH] event;
  char[STRING_LENGTH] medal;
}

typedef struct olympian olympian_t

struct node{

  node* left;
  node* right;
  // STAGE TWO node* next;

  char[STRING_LENGTH] key;

};

typedef struct node bt_node_t;

bt_node_t bst_make_tree(){
  return NULL;
}

bt_node_t bst_insert(bst_node *root, char* key){

  if (root == NULL) {
    root = malloc(sizeof(bst_node));
    root->left = NULL;
    root->right = NULL;
    /* root->value = data to be inserted*/
    return root;

  }
  /* CASE 2
  else if(root->key == key){
    root->next = insert_equal_key(root->next);
  }
  */

  //NEED TO USE strcmp for key comparisons
  else if (root->key <= NULL)
  {
    root->left = bst_insert(root->left, key);
  }
  else if (root->key > NULL)
  {
    root->right = bst_insert(root->right, key);
  }

  return root;
}

bt_node_t insert_equal_key(bt_node_t *root){
  if(root->next == NULL)
  {
    root->next = malloc(sizeof(bt_node_t));
    //populate data
  }
  else{
    root->next = insert_equal_key(root->next);
  }

}

bt_node_t traverse(bt_node_t *root){
  if(root == NULL)
  {
    return root;
  }
  traverse(root->left);
  traverse(root->right);
}
