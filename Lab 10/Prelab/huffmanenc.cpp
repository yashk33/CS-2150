#include <iostream>
#include <fstream>
#include <cstdlib>

#include <stdio.h>
#include <stdlib.h>

#include <unordered_map>

#include "heap.h"
#include "huffmanNode.h"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    FILE *file = fopen(argv[1], "r");

    heap mainTree;
    unordered_map<string, int> characters;
    unordered_map<string, string> codes;
    
    int symbols, distinctSymbols;
    double originalFile, compressedFile, compressionRatio, bitsPerCharacter;

    char g;
    while (((g = fgetc(file)) != EOF)) {
      if(int(g) > 31) {
       string str(1, g);

	 if(characters.end() != characters.find(str))
	   characters[str] = characters[str] + 1;
     
	 else
	   characters.insert(make_pair(str, 1));

       symbols++;
      }
      
      else
	continue;
    }

    if (characters.end() != characters.find(" ")){
       characters.insert(make_pair("space", characters[" "]));
       characters.erase(" ");
    }
     

    rewind(file);

    for(auto it : characters){
      huffmanNode* node = new huffmanNode();
      
      node->val = it.first;
      node->frequency = it.second;

      mainTree.insert(node);

      distinctSymbols++;
    }

    while(mainTree.size() > 1){
      huffmanNode* temp, *leftMin, *rightMin;
      
      temp = new huffmanNode();
      leftMin = mainTree.deleteMin();
      rightMin = mainTree.deleteMin();

      temp->left = leftMin;
      temp->right = rightMin;
      temp->frequency = leftMin->frequency + rightMin->frequency;
      temp->val = " ";
      
      mainTree.insert(temp);
    }

    huffmanNode* pass = mainTree.findMin();
    huffmanNode* temp = new huffmanNode();

    temp->codes("", pass);

    codes = temp->cds;

    while(((g = fgetc(file)) != EOF)){
      if(int(g) > 31 && int(g) < 127){
       string str(1, g);
       originalFile++;

       if(int(g) != 32)
	 compressedFile = compressedFile + codes[str].length();

       else
	 compressedFile = compressedFile + codes["space"].length();
      }

      else
	continue;
    }

    cout << "----------------------------------------" << endl;
    cout << temp->ret << endl;
    cout << "----------------------------------------" << endl;
    
    cout << "There are a total of " << symbols << " symbols that are encoded." << endl;
    cout << "There are " << distinctSymbols << " distinct symbols used." << endl;
    cout << "There were " << originalFile*8 << " bits in the original file." << endl;
    cout << "There were " << compressedFile << " bits in the compressed file." << endl;
    cout << "This gives a compression ratio of " << originalFile*8/compressedFile << "." << endl;      
    cout << "The cost of the Huffman tree is " << compressedFile/originalFile << " bits per character." << endl;

    // close the file
    fclose(file);
    return 0;
}
