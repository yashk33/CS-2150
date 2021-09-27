// Yash Kolli, ysk6dw, 4/27/21, huffmanNode.h

#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <unordered_map>

using namespace std;

class huffmanNode {
      public:
	huffmanNode();
	huffmanNode(string val);
	~huffmanNode();

        void codes(string code, huffmanNode* node);

	huffmanNode* left;
	huffmanNode* right;
  
	string val;
        string ret;
	int frequency;
        unordered_map<string, string> cds;
};

#endif
