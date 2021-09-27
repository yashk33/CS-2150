#include "AVLNode.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
using namespace std;

AVLTree::AVLTree() {
    root = NULL;
}

AVLTree::~AVLTree() {
    delete root;
    root = NULL;
}

AVLNode* AVLTree::insert(const string& x, AVLNode*& node) const{
  if(node == NULL){
    node = new AVLNode();
    node->value = x;
  }

  else if(x < node->value){
    node->left = insert(x, node->left);
    
    if(height(node->left) - height(node->right) == 2){
      if(!(x < node->left->value))
	node->left = rotateLeft(node->left);
      node = rotateRight(node);
    }
  }

  else if(x > node->value){
    node->right = insert(x, node->right);
    
    if(height(node->right) - height(node->left) == 2){
      if(!(x > node->right->value))
	node->right = rotateRight(node->right);
      node = rotateLeft(node);
    }
  }

  node->height = max(height(node->left), height(node->right)) + 1;
  
  return node;
}

// insert finds a position for x in the tree and places it there.
void AVLTree::insert(const string& x) {
    // YOUR IMPLEMENTATION GOES HERE
   insert(x, root);
}

// remove finds x's position in the tree and removes it, rebalancing as
// necessary.
void AVLTree::remove(const string& x) {
    root = remove(root, x);
}

string AVLTree::pathTo(const string& x, AVLNode* node, string path) const{
  
  if(node->value == x){
    return path + node->value;
  }

  else if(x < node->value){
    path = path + node->value + " ";
    return pathTo(x, node->left, path);
  }

  else if(x > node->value){
    path = path + node->value + " ";
    return pathTo(x, node->right, path);
  }

  return "";
}

// pathTo finds x in the tree and returns a string representing the path it
// took to get there.
string AVLTree::pathTo(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  string ret = "";
  
  if(find(x) == false)
    return ret;
  
  return pathTo(x, root, ret);
}

bool AVLTree::find(const string& x, AVLNode* node) const{
  if(node->value == x)
    return true;

  if(node->right == NULL && node->left != NULL)
    return find(x, node->left);

  if(node->right != NULL && node->left == NULL)
    return find(x, node->right);
  
  if(node->right == NULL && node->left == NULL)
    return false;

  return find(x, node->left) || find(x, node->right);
}

// find determines whether or not x exists in the tree.
bool AVLTree::find(const string& x) const {
    // YOUR IMPLEMENTATION GOES HERE
  return find(x, root);
}

int AVLTree::numNodes(AVLNode* node) const{
  int ret = 1;

  if(node == NULL)
    return 0;

  else{
    ret = ret + numNodes(node->left) + numNodes(node->right);
    return ret;
  }

}

// numNodes returns the total number of nodes in the tree.
int AVLTree::numNodes() const {
    // YOUR IMPLEMENTATION GOES HERE
  return numNodes(root);  
}

// balance makes sure that the subtree with root n maintains the AVL tree
// property, namely that the balance factor of n is either -1, 0, or 1.
void AVLTree::balance(AVLNode*& n) const{
    // YOUR IMPLEMENTATION GOES HERE
  
  if(height(n->right) - height(n->left) == 2){
    if(height(n->right->right) - height(n->right->left) < 0)
      n->right = rotateRight(n);
    n = rotateLeft(n);
  }

  else if(height(n->right) - height(n->left) == -2){
    if(height(n->left->right) - height(n->left->left) > 0)
      n->left = rotateLeft(n);
    n = rotateRight(n);
  }
}

// rotateRight performs a single rotation on node n with its left child.
AVLNode* AVLTree::rotateRight(AVLNode*& n) const{
  if(n->left != NULL){
    AVLNode* temp = n->left;
 
    n->left = temp->right;
    temp->right = n;

    n->height = max(height(n->left), height(n->right)) + 1;
    temp->height = max(height(temp->left), n->height) + 1;

    return temp;
  }
  return n;
}

// rotateLeft performs a single rotation on node n with its right child.
AVLNode* AVLTree::rotateLeft(AVLNode*& n) const {
    // YOUR IMPLEMENTATION GOES HERE
  if(n->right != NULL){
    AVLNode* temp = n->right;
 
    n->right = temp->left;
    temp->left = n;

    n->height = max(height(n->left), height(n->right)) + 1;
    temp->height = max(height(n->right), n->height) + 1;

    return temp;
  }
  return n;
}

// private helper for remove to allow recursion over different nodes.
// Returns an AVLNode* that is assigned to the original node.
AVLNode* AVLTree::remove(AVLNode*& n, const string& x) {
    if (n == NULL) {
        return NULL;
    }

    // first look for x
    if (x == n->value) {
        // found
        if (n->left == NULL && n->right == NULL) {
            // no children
            delete n;
            n = NULL;
            return NULL;
        } else if (n->left == NULL) {
            // Single child (left)
            AVLNode* temp = n->right;
            n->right = NULL;
            delete n;
            n = NULL;
            return temp;
        } else if (n->right == NULL) {
            // Single child (right)
            AVLNode* temp = n->left;
            n->left = NULL;
            delete n;
            n = NULL;
            return temp;
        } else {
            // two children -- tree may become unbalanced after deleting n
            string sr = min(n->right);
            n->value = sr;
            n->right = remove(n->right, sr);
        }
    } else if (x < n->value) {
        n->left = remove(n->left, x);
    } else {
        n->right = remove(n->right, x);
    }

    // Recalculate heights and balance this subtree
    n->height = 1 + max(height(n->left), height(n->right));
    balance(n);

    return n;
}

// min finds the string with the smallest value in a subtree.
string AVLTree::min(AVLNode* node) const {
    // go to bottom-left node
    if (node->left == NULL) {
        return node->value;
    }
    return min(node->left);
}

// height returns the value of the height field in a node.
// If the node is null, it returns -1.
int AVLTree::height(AVLNode* node) const {
    if (node == NULL) {
        return -1;
    }
    return node->height;
}

// max returns the greater of two integers.
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Helper function to print branches of the binary tree
// You do not need to know how this function works.
void showTrunks(Trunk* p) {
    if (p == NULL) return;
    showTrunks(p->prev);
    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void AVLTree::printTree(AVLNode* root, Trunk* prev, bool isRight) {
    if (root == NULL) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight) {
        trunk->str = ".---";
        prev_str = "   |";
    } else {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->value << endl;

    if (prev) prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);

    delete trunk;
}

void AVLTree::printTree() {
    printTree(root, NULL, false);
}
