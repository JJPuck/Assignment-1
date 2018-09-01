/* ***************************

* Created by Jordan Puckridge 20/8/2018
*
* Header file and function prototypes for binary search tree
implementation
*
*/

/* declaration of nodes and typedefs */
struct node;
typedef struct node bt_node;

/* Returns NULL to create a base instance of a tree  */
bt_node bst_make_tree();
/* Insert a new element into the binary search tree */
bt_node bst_insert(bst_node *root, int key);
/* insert a node with equal key value into a linked list within tree */
bt_node insert_equal_key(bt_node *root);
/*  traverse through the binary search tree*/
bt_node traverse(bt_node *root);
