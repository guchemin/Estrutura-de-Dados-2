#include "trie.h"

int main () {

  Trie *root = create_node ('\0');

  root = insert (root, "mesa");
  root = insert (root, "me");

  print (root, 0);

  delete(root, "mesa");
  delete(root, "mesa");
  
  printf("\n\n\n\n\n");

  print (root, 0);

  return 0;
}