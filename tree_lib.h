#include <iostream>
#include <vector>


using namespace std;



// Note: The terms "leaf" and "node" are used a lot in this and are the same thing
// ^ this is because I changed the class name from Node to Leaf
class Leaf {
    public:

        // Just made it able to acctually hold a peice of data
        string data;

        // Right & left child leafs
        Leaf *left = NULL;
        Leaf *right = NULL;

        // default value
        // value: basically a header or name of the node in this
        // ^ you don't want to edit this or some weird stuff might happen
        int value;

        // very simple leaf initialization
        Leaf (int val) {
          this->value = val;
        }
        void del() {
          delete left;
          delete right;
          delete this;
        }




};
class Tree {
    public:

      // "nodes" is the root node or leaf
      Leaf *nodes;
      int  node_count=1;

      //Initializes the root node
      Tree (int root_value) {
        this->nodes = new Leaf(root_value);
      }

      // gets a leaf by its value/header
      // you can edit the leaf through this too, because I am using pointers too much, oh well
      Leaf *get_leaf(int value) {

        // current_node: used for sorting through the nodes/leafs
        Leaf *current_node = this->nodes;


        // loops through the leafs and moves from leaf to leaf in the correct order
        for (int pos=0; pos<this->node_count; pos++) {

          // if the current nodes value/header is equal to the value/header we are looking for, return the node
          if (current_node->value==value) {
            return current_node;
          }

          // Set current node to this leafs left child node if current leafs val < search header/val
          else if (current_node->value < value) {
            current_node = current_node->left;

            // If the left node is null, break, we couldn't find the node with the correct value/header
            if (current_node==NULL) break;
          }

          // Set current node to this leafs right child node if current leafs val > search header/val
          else if (current_node->value > value) {
            current_node = current_node->right;
          // If the right node is null, break, we couldn't find the node with the correct value/header
            if (current_node==NULL) break;
          }

        }

        // delete the pointer
        delete &current_node;

        // leaf couldn't be found
        return NULL;
      }

      // adds a leaf/node to the tree
      // less comments in this section because a lot of it is explained by the get_node function
      void add_leaf(Leaf *new_node) {

        // current_node: used for sorting through the leafs/nodes
        Leaf *current_node = this->nodes;

        // node_count: gotta keep track of how many nodes there are!
        this->node_count+=1;


        for(int i=0;i<this->node_count;i++) {


          if (current_node->value < new_node->value) {

            // if the current nodes left child leaf is NULL than replace it with the new node
            if (current_node->left==NULL) {
              current_node->left = new_node;
              break;
              }

            current_node = current_node->left;





          }
          else if (current_node->value > new_node->value) {

            // if the current nodes left child leaf is NULL than replace it with the new node
            if (current_node->right==NULL) {
              current_node->right = new_node;
              break;
            }
            current_node = current_node->right;
         }

          }

         // clears pointer from mem
         delete &current_node;

      }

      // gets a leaf and deletes it, very simple
      void delete_leaf(int value) {
        this->get_leaf(value)->del();
      }

      // clears all nodes/leafs except the root
      void clear() {
        int val =  this->nodes->value;
        delete nodes;
        nodes = new Leaf(val);
      }

      // delets the tree as a whole
      void del() {
        // clears the current Tree from memory
        delete nodes;
        delete this;
      }
};
