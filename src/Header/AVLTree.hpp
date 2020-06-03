#include "../Implementation/Node.cpp"
#include <iostream>

class AVLTree {
	Node *root {nullptr};

	int getHeight(Node *node); //Get the height position of nodes in the tree
	int getBalanceFactor(Node *node); //Get balance factor for nodes to determine their rotation
	Node *rotateToR(Node *node); //Rotation for LL Imbalance
	Node *rotateToLToR(Node *node); //Rotation for LR Imbalance
	Node *rotateToL(Node *node); //Rotation for RR Imbalance
	Node *rotateToRToL(Node *node); //Rotation for RL Imbalance
	Node *insert(Node *node, int value); //Insert node

	public:
		Node *getRoot(); //Get the root node of the tree
		int insert(int value); //Insert node for public uses
};
