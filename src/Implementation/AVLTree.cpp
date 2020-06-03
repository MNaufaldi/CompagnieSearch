#include "../Header/AVLTree.hpp"
#include <iostream>

using std::cout;
using std::endl;


//Gets the height of a node
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


//Performs node rotation To Right (LL Imbalance)
Node *AVLTree::rotateToR(Node *node) {
    //Sets the position of nodes
    Node *temp = node->lPtr;
    node->lPtr = temp->rPtr;
    temp->rPtr = node;

    //Updates the height of swaped nodes
    node->height = this->getHeight(node);
    temp->height = this->getHeight(temp);

    //Updates the root if the position of previous root swapped
    if (node == this->root) {
        this->root = temp;
    }

    return temp;
}


//Performs node rotation To Left then To Right (LR Imbalance)
Node *AVLTree::rotateToLToR(Node *node) {
    //Sets the position of nodes
    Node *temp = node->lPtr->rPtr;
    node->lPtr->rPtr = temp->lPtr;
    temp->lPtr = node->lPtr;
    node->lPtr = temp->rPtr;
    temp->rPtr = node;

    //Updates the height of swaped nodes
    node->height = this->getHeight(node);
    temp->height = this->getHeight(node);
    temp->lPtr->height = this->getHeight(temp->lPtr);

    //Updates the root if the position of previous root swapped
    if (node == this->root) {
        this->root = temp;
    }

    return temp;

}


//Perform node rotation To Left (RR Imbalance)
Node *AVLTree::rotateToL(Node *node) {
    //Sets the position of nodes
    Node *temp = node->rPtr;
    node->rPtr = temp->rPtr;
    temp->lPtr = node;

    //Updates the height of swaped nodes
    node->height = this->getHeight(node);
    temp->height = this->getHeight(temp);

    //Updates the root if the position of previous root swapped
    if (node == this->root) {
        this->root = temp;
    }

    return temp;
}


//Performs node rotation To Right then To Left (RL Imbalance)
Node *AVLTree::rotateToRToL(Node *node) {
    //Sets the position of nodes
    Node *temp = node->rPtr->lPtr;
    node->rPtr->lPtr = temp->rPtr;
    temp->rPtr = node->rPtr;
    node->rPtr = temp->lPtr;
    temp->lPtr = node;

    //Updates the height of swaped nodes
    node->height = this->getHeight(node);
    temp->height = this->getHeight(node);
    temp->rPtr->height = this->getHeight(temp->rPtr);

    //Updates the root if the position of previous root swapped
    if (node == this->root) {
        this->root = temp;
    }

    return temp;
}


//Inserts value to tree
Node *AVLTree::insert(Node *node, int value) {
    //Set the root if none presents in the tree
    if (this->root == nullptr) {
        this->root = new Node(value);
        return this->root;
    }

    //Create new node at the leaf of the tree
    if (node == nullptr) {
        node = new Node(value);
        return node;
    }

    //Get to the leaf of the tree
    if (value < node->value) {
        //Put left if value is smaller
        node->lPtr = insert(node->lPtr, value);
    } else if (value > node->value) {
        //Put right if value is bigger
        node->rPtr = insert(node->rPtr, value);
    } else {
        //Put to linked list if value is equal
        Node *tempNode = node
        while(tempNode->cPtr) {
            tempNode = tempNode->cPtr;
        }
        tempNode->cPtr = new Node(value);
    }

    //Update the height of the nodes traversed by the new value
    node->height = this->getHeight(node);

    //Check which rotation to take
    if (this->getBalanceFactor(node) == 2 && this->getBalanceFactor(node->lPtr) == 1) {
        //LL Imbalance
        return this->rotateToR(node);
    } else if (this->getBalanceFactor(node) == 2 && this->getBalanceFactor(node->lPtr) == -1) {
        //LR Imbalance
        return this->rotateToLToR(node);
    } else if (this->getBalanceFactor(node) == -2 && this->getBalanceFactor(node->rPtr) == -1) {
        //RR Imbalance
        return this->rotateToL(node);
    } else if (this->getBalanceFactor(node) == -2 && this->getBalanceFactor(node->rPtr) == 1) {
        //RL Imbalance
        return this->rotateToRToL(node);
    }

    return node;
}


//Public Functions

//Inserts value to tree
int AVLTree::insert(int value) {
    //Try-Catch error from insert function
    try {
        this->insert(this->getRoot(), value);
    } catch (...) {
        return -1;
    }

    return 0;
}


//Gets the root of the tree
Node *AVLTree::getRoot() {
    return this->root;
}
