/**
 * liner_normal.cpp
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


/* main function */
int main(int argc, char *argv[]) {
  // Variables declarations
  int id;
  string value;
  fstream ifs;
  system_clock::time_point t_st, t_ed;
  NodeLiner *nodeRoot, *nodeNext;

  // Argument checking
  if(argc < 3) {
    cerr << "Invalid arguments." << endl;
    cerr << "  Useage:" << endl;
    cerr << "    " << argv[0] << " <Input data file> <Search id 1> <Search id 2> ..." << endl;
    exit(EXIT_FAILURE);
  }

  // Data reading
  //// File open
  ifs.open(argv[1]);
  //// Timer start
  t_st = system_clock::now();
  //// Initial node make
  ifs >> id >> value;
  nodeRoot = new NodeLiner(id, value);
  nodeNext = nodeRoot;
  //// Other node make
  while(ifs >> id >> value) {
    nodeNext = nodeNext->makeNextNode(id, value);
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
    nodeNext = nodeRoot;
    while((nodeNext->getId() != id) && (nodeNext->getNextNode() != NULL)) {
      nodeNext = nodeNext->getNextNode();
    }
    // Search result printing
    if(nodeNext->getId() == id) {
      cout << argv[i] << " " << nodeNext->getValue();
    } else {
      cout << argv[i] << " Not-found";
    }
    // Timer stop
    t_ed = system_clock::now();
    // Data searching time printing
    cout << " " << duration_cast<microseconds>(t_ed - t_st).count() << endl;
  }

  // Quit
  if(nodeRoot != NULL) {
    delete nodeRoot;
  }
  return 0;
}
