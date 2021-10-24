/**
 * liner_hash.cpp
 *
 * Author: aKuad
 *
 * Published with CC0 license
 */

/* Headers incliding */
#include <iostream>
#include <fstream>
#include <chrono>
#include "NodeLiner.h"

#define HASH_SIZE 100
//#define HASH_FUNC i%100

using namespace std;
using namespace std::chrono;


/* main function */
int main(int argc, char *argv[]) {
  // Variables declarations
  int id, hash;
  string value;
  fstream ifs;
  system_clock::time_point t_st, t_ed;
  NodeLiner *nodeRoot[HASH_SIZE] = {};
  NodeLiner *nodeNext[HASH_SIZE] = {};
  NodeLiner *curNode;

  // Argument checking
  if(argc < 3) {
    cerr << "Invalid argument" << endl;
    exit(EXIT_FAILURE);
  }

  // Data reading
  //// File open
  ifs.open(argv[1]);
  //// Timer start
  t_st = system_clock::now();
  //// Other node make
  while(ifs >> id >> value) {
    hash = id % HASH_SIZE;
    if(nodeRoot[hash] != NULL) {
      nodeNext[hash] = nodeNext[hash]->makeNextNode(id, value);
    } else {
      nodeRoot[hash] = new NodeLiner(id, value);
      nodeNext[hash] = nodeRoot[hash];
    }
  }
  //// Timer stop
  t_ed = system_clock::now();
  //// File close
  ifs.close();
  //// Data reading time printing
  cout << duration_cast<microseconds>(t_ed - t_st).count() << endl;

  // Data searching
  for(int i = 2; i < argc; i++) {
    // Timer start
    t_st = system_clock::now();
    // Data searching
    //cout << argv[i] << " " << nodeRoot->searchFromId(atoi(argv[i])) << endl;
    id = atoi(argv[i]);
    hash = id % HASH_SIZE;
    curNode = nodeRoot[hash];
    while((curNode->getId() != id) && (curNode->getNextNode() != NULL)) {
      curNode = curNode->getNextNode();
    }
    // Search result printing
    if(curNode->getId() == id) {
      cout << argv[i] << " " << curNode->getValue();
    } else {
      cout << argv[i] << " Not-found";
    }
    // Timer stop
    t_ed = system_clock::now();
    // Data searching time printing
    cout << " " << duration_cast<microseconds>(t_ed - t_st).count() << endl;
  }

  // Quit
  for(int i = 0; i < HASH_SIZE; i++) {
    if(nodeRoot[i] != NULL) {
      delete nodeRoot[i];
    }
  }
  return 0;
}
