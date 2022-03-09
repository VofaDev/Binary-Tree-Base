#include <iostream>
#include "tree_lib.h"


using namespace std;



// DO NOT EDIT LEAF VALUE
// E.G. t->get_leaf(10)->value = x;
// ^ DON'T DO THAT
int main() {

  //  initialize a new binary search tree
  Tree *t = new Tree(50);

  //  makes 100 leafs
  for (int i=0; i<100;i++) {
    t->add_leaf(new Leaf(i));
  }

  // editing node data example
  t->get_leaf(10)->data = "Hello, World!";
  cout << t->get_leaf(10)->data << "\n";

  // delete leaf example
  t->delete_leaf(10);

  // re-creates leaf
  t->add_leaf(new Leaf(10));
  t->get_leaf(10)->data = "Hello again, World!";
  cout << t->get_leaf(10)->data << "\n";

  // delete the tree from memory
  t->del();
};
