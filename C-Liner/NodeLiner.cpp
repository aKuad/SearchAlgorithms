/**
 * NodeLiner.cpp
 *
 * Author: aKuad
 *
 * Published with CC0 license
 */

/* Headers incliding */
#include "NodeLiner.h"

/* Constructor */
NodeLiner::NodeLiner(int id, std::string value) {
  this->id = id;
  this->value = value;
  this->nextNode = NULL;
}

/* Destructor */
NodeLiner::~NodeLiner() {
  if(this->nextNode != NULL) {
    delete this->nextNode;
  }
}

/* Method - Making new node to end of liner structure */
/*   return: created new node pointer */
NodeLiner* NodeLiner::makeNextNode(int id, std::string value) {
  if(this->nextNode != NULL) {
    // When next node is exist
    return this->nextNode->makeNextNode(id, value);
  } else {
    // When not
    this->nextNode = new NodeLiner(id, value);
    return this->nextNode;
  }
  return NULL;
}
