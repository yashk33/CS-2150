// Yash Kolli, ysk6dw, 4/27/21, huffmanNode.cpp

#include <iostream>
#include <string>
#include <cstddef>
#include <unordered_map>

#include "huffmanNode.h"

using namespace std;

huffmanNode::huffmanNode(){
  left = NULL;
  right = NULL;

  val = "";
  ret = "";
  frequency = 0;
}

huffmanNode::huffmanNode(string val){
  left = NULL;
  right = NULL;

  val = val;
  ret = "";
  frequency = 0;
}

huffmanNode::~huffmanNode(){
  val = "";
  frequency = 0;
}

void huffmanNode::codes(string code, huffmanNode* node){
  if(node == NULL)
    return;

  if(node->val != " "){
    cds.insert(make_pair(node->val, code));
    cout << node->val << ": " << code << endl;
    ret = ret + code + " ";
  }

  this->codes(code + "0", node->left);
  this->codes(code + "1", node->right);   
}

void huffmanNode::tree(string code, huffmanNode* node){
  if(node == NULL)
    exit(1);

  if(!(cds.find(code) == cds.end()))
    node->val = cds[code];

  else {
    node->val = "break";
    node->right = new huffmanNode();
    node->left = new huffmanNode();
    
    this->tree(code + "0", node->left);
    this->tree(code + "1", node->right);
  }
}
