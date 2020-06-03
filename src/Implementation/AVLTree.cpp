#include "../Header/AVLTree.hpp"
#include <iostream>

using std::cout;
using std::endl;


//Get the height of a node
int AVLTree::getHeight(Node *node) {
    int lHeight = (node && node->lPtr) ? node->lPtr->height : 0;
    int rHeight = (node && node->rPtr) ? node->rPtr->height : 0;
    return (lHeight > rHeight) ? lHeight + 1 : rHeight + 1;
}


//Get the balance factor for determining rotation action
int AVLTree::getBalanceFactor(Node *node) {
    int lHeight = (node && node->lPtr) ? node->lPtr->height : 0;
    int rHeight = (node && node->rPtr) ? node->rPtr->height : 0;
    return lHeight - rHeight;
}


//Perform node rotation To Right (LL Imbalance)
Node *AVLTree::rotateToR(Node *node) {
    Node *temp = node->lPtr;
    node->lPtr = temp->rPtr;
    temp->rPtr = node;

    node->height = this->getHeight(node);
    temp->height = this->getHeight(temp);

    if (node == this->root) {
        this->root = temp;
    }

    return temp;
}


//Perform node rotation To Left then To Right (LR Imbalance)
Node *AVLTree::rotateToLToR(Node *node) {
    Node *temp = node->lPtr->rPtr;
    node->lPtr->rPtr = temp->lPtr;
    temp->lPtr = node->lPtr;
    node->lPtr = temp->rPtr;
    temp->rPtr = node;

    node->height = this->getHeight(node);
    temp->height = this->getHeight(node);
    temp->lPtr->height = this->getHeight(temp->lPtr);

    if (node == this->root) {
        this->root = temp;
    }

    return temp;

}


//Perform node rotation To Left (RR Imbalance)
Node *AVLTree::rotateToL(Node *node) {
    Node *temp = node->rPtr;
    node->rPtr = temp->rPtr;
    temp->lPtr = node;

    node->height = this->getHeight(node);
    temp->height = this->getHeight(temp);

    if (node == this->root) {
        this->root = temp;
    }

    return temp;
}


//Perform node rotation To Right then To Left (RL Imbalance)
Node *AVLTree::rotateToRToL(Node *node) {
    Node *temp = node->rPtr->lPtr;
    node->rPtr->lPtr = temp->rPtr;
    temp->rPtr = node->rPtr;
    node->rPtr = temp->lPtr;
    temp->lPtr = node;

    node->height = this->getHeight(node);
    temp->height = this->getHeight(node);
    temp->rPtr->height = this->getHeight(temp->rPtr);

    if (node == this->root) {
        this->root = temp;
    }

    return temp;
}


//Inserting value
Node *AVLTree::insert(Node *node, int value) {
    if (this->root == nullptr) {
        this->root = new Node(value);
        return this->root;
    }

    if (node == nullptr) {
        node = new Node(value);
        return node;
    }

    if (value < node->value) {
        node->lPtr = insert(node->lPtr, value);
    } else if (value > node->value) {
        node->rPtr = insert(node->rPtr, value);
    } else {
        Node *tempNode = node
        while(tempNode->cPtr) {
            tempNode = tempNode->cPtr;
        }
        tempNode->cPtr = new Node(value);
    }

    node->height = this->getHeight(node);

    if (this->getBalanceFactor(node) == 2 && this->getBalanceFactor(node->lPtr) == 1) {
        return this->rotateToR(node);
    } else if (this->getBalanceFactor(node) == 2 && this->getBalanceFactor(node->lPtr) == -1) {
        return this->rotateToLToR(node);
    } else if (this->getBalanceFactor(node) == -2 && this->getBalanceFactor(node->rPtr) == -1) {
        return this->rotateToL(node);
    } else if (this->getBalanceFactor(node) == -2 && this->getBalanceFactor(node->rPtr) == 1) {
        return this->rotateToRToL(node);
    }

    return node;
}


//Public Function
int AVLTree::insert(int value) {
    try {
        this->insert(this->getRoot(), value);
    } catch (...) {
        return -1;
    }

    return 0;
}


//Get the root of the tree
Node *AVLTree::getRoot() {
    return this->root;
}
