/**
 * NodeLiner.h
 *
 * Author: aKuad
 *
 * Published with CC0 license
 */

/* Headers including */
#include <iostream>

/* Class declarations */
class NodeLiner {
  private:
    int id = 0;
    std::string value = "";
    NodeLiner *nextNode;

  public:
    // Constructor and destructor
    NodeLiner(int id, std::string value);
    ~NodeLiner();

    // Getter
    int getId() const { return this->id; }
    std::string getValue() const { return this->value; }
    NodeLiner* getNextNode() const { return this->nextNode;}

    // Methods
    NodeLiner* makeNextNode(int id, std::string value);
};
