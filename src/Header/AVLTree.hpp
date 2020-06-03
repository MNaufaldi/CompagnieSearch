#include "../Implementation/Node.cpp"
#include <iostream>

class AVLTree {
	Node *root {nullptr};

	int getHeight(Node *node);
	int getBalanceFactor(Node *node);
	Node *rotateToR(Node *node);
	Node *rotateToLToR(Node *node);
	Node *rotateToL(Node *node);
	Node *rotateToRToL(Node *node);
	Node *insert(Node *node, int value);

	public:
		Node *getRoot();
		int insert(int value);
};
