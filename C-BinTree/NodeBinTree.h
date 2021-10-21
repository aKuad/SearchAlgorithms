/**
 * NodeBinTree.h
 *
 * Author: aKuad
 *
 * Published with CC0 license
 */

/* Headers including */
#include <iostream>

/* Class declarations */
class NodeBinTree {
  private:
    int id;
    std::string value;
    NodeBinTree *node_high;
    NodeBinTree *node_low;

  public:
    // Constructor and destructor
    NodeBinTree(int id, std::string value);
    ~NodeBinTree();

    // Getter
    int getId() { return this->id; }
    std::string getValue() { return this->value; }
    NodeBinTree* getNodeHigh() { return this->node_high; }
    NodeBinTree* getNodeLow() { return this->node_low; }

    // Methods
    NodeBinTree* makeNewNode(int id, std::string value);
    std::string searchFromId(int id);
};
