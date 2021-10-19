/**
 * NodeBinTree.cpp
 *
 * Author: aKuad
 *
 * Published with CC0 license
 */

/* Header including */
#include "NodeBinTree.h"

/* Constructor */
NodeBinTree::NodeBinTree(int id, std::string value) {
  this->id = id;
  this->value = value;
  this->node_high = NULL;
  this->node_low = NULL;
}

/* Destructor */
NodeBinTree::~NodeBinTree() {
  if(this->node_high != NULL) { delete this->node_high; }
  if(this->node_low != NULL) { delete this->node_low; }
}

/* Method - Making new node to end of liner structure */
/*   return: created new node pointer */
NodeBinTree* NodeBinTree::makeNewNode(int id, std::string value) {
  if(this->id < id) {
    // When next id is higher than this node
    if(this->node_high != NULL) {
      // When high node is exist
      return this->node_high->makeNewNode(id, value);
    } else {
      // When not
      this->node_high = new NodeBinTree(id, value);
      return this->node_high;
    }
  } else if(this->id > id) {
    // When next id is lower than this node
    if(this->node_low != NULL) {
      // When low node is exist
      return this->node_low->makeNewNode(id, value);
    } else {
      // When not
      this->node_low = new NodeBinTree(id, value);
      return this->node_low;
    }
  } else {
    // When next id is same as this node
    // return NULL (Failed to create)
    return NULL;
  }
}
