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

using namespace std;
using namespace std::chrono;


/* Parameters settings */
#define HASH_SIZE 100
#define HASH_FUNC id % HASH_SIZE
#define NAME_DT argv[1]


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
    cerr << "Invalid arguments." << endl;
    cerr << "  Useage:" << endl;
    cerr << "    " << argv[0] << " <Input data file> <Search id 1> <Search id 2> ..." << endl;
    exit(EXIT_FAILURE);
  }

  // Data reading
  //// File open
  ifs.open(NAME_DT);
  //// Timer start
  t_st = system_clock::now();
  //// Other node make
  while(ifs >> id >> value) {
    hash = HASH_FUNC;
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
    hash = HASH_FUNC;
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
