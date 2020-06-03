#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#include "Header/AVLTree.hpp"

int main() {
    AVLTree avl = AVLTree();

    avl.insert(10);
    avl.insert(5);
    avl.insert(7);

    cout << avl.getRoot()->value << endl;
    cout << avl.getRoot()->lPtr->value << endl;
    cout << avl.getRoot()->rPtr->value << endl;
    return 0;
}
