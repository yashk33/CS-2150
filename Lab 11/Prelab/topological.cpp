//Yash Kolli, ysk6dw, 5/3/21, topological.cpp

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <deque>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    struct Node {
      int indegree = 0;
      string currLoc;
      vector<Node*> neighbors;
    };

    vector<Node*> order;
    deque<string> ret;
    
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    while(!file.eof()) {

      // read in two strings
      string s1, s2;
      file >> s1;
      file >> s2;

      if(s1 == "0" && s2 == "0")
	break;

      int strIndex1 = 0;
      int strIndex2 = 0;
     
      int temp = -1;
      
      for(Node* n : order){
        temp++;
	
	if(n->currLoc == s1)
	  strIndex1 = temp;
	  
	if(n->currLoc == s2)
	  strIndex2 = temp;
      }

      Node* key1 = new Node();
      key1->currLoc = s1;

      if(!(find(order.begin(), order.end(), key1) != order.end())){
	order.push_back(key1);
	strIndex1 = order.size() - 1;
      }

      Node* key2 = new Node();
      key2->currLoc = s2;

      if(!(find(order.begin(), order.end(), key2) != order.end())){
	order.push_back(key2);
	strIndex2 = order.size() - 1;
      }

      Node* ins = order.at(strIndex2);
      ins->indegree = 1;
      
      order[strIndex1]->neighbors.push_back(ins);
    }

    Node* n1;
    string store = "";

    for(int i = 0; i < order.size(); i++){
      if(order.at(i)->indegree == 0)
	ret.push_front(order.at(i)->currLoc);
    }

    while(!ret.empty()){
      sort(ret.begin(), ret.end());
      for(int i = 0; i < order.size(); i++){
	if(order.at(i)->currLoc == ret.front()){
	  n1 = new Node();
	  n1->currLoc = ret.front();
	}
      }

      ret.pop_front();
      if(store.find(n1->currLoc) == string::npos){
	cout << n1->currLoc << " ";
	store = store + n1->currLoc;
      }

      for(int k = 0; k < n1->neighbors.size(); k++){
	if(n1->neighbors.at(k)->indegree-- == 0)
	  ret.push_front(n1->neighbors.at(k)->currLoc);
      }
    }

    cout << endl;
    file.close();
    return 0;
}
