//Yash Kolli, ysk6dw, 4/29/21 huffmandec.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include <unordered_map>
#include "huffmanNode.h"

using namespace std;

// main(): we want to use parameters
int main (int argc, char** argv) { 
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    unordered_map<string, string> decode;

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
	
        // do something with the prefix code
        decode.insert(make_pair(prefix, character));
    }

    
    huffmanNode* rootNode = new huffmanNode();
    rootNode->cds = decode;
    rootNode->tree("", rootNode);

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();

    huffmanNode* traverse = rootNode;

    for(char c : allbits){
      if(c == '0')
	traverse = traverse->left;

      if(c == '1')
	traverse = traverse->right;

      if(traverse->val != "break"){
	cout << traverse->val;
	traverse = rootNode;
      }
    }

    cout << endl;

    return 0;
}
