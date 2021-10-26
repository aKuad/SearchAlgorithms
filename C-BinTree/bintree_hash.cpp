/**
 * bintree_hash.cpp
 *
 * Author: aKuad
 *
 * Published with CC0 license
 */

/* Headers including */
#include <iostream>
#include <fstream>
#include <chrono>
#include "NodeBinTree.h"

#define HASH_SIZE 100

using namespace std;
using namespace std::chrono;


/* main function */
int main(int argc, char* argv[]) {
  // Variables declarations
  int id, hash;
  string value;
  fstream ifs;
  system_clock::time_point t_st, t_ed;
  NodeBinTree *nodeTop[HASH_SIZE] = {};

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
  //// Initial node make
  while(ifs >> id >> value) {
    hash = id % HASH_SIZE;
    if(nodeTop[hash] != NULL) {
      nodeTop[hash]->makeNewNode(id, value);
    } else {
      nodeTop[hash] = new NodeBinTree(id, value);
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
    id = atoi(argv[i]);
    hash = id % HASH_SIZE;
    cout << id << " " << nodeTop[hash]->searchFromId(id);
    // Timer stop
    t_ed = system_clock::now();
    // Data searching time printing
    cout << " " << duration_cast<microseconds>(t_ed - t_st).count() << endl;
  }

  // Quit
  for(int i = 0; i < HASH_SIZE; i++) {
    if(nodeTop[i] != NULL) {
      delete nodeTop[i];
    }
  }
  return 0;
}
