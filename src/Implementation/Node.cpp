struct Node{
    int value;
    Node *lPtr {nullptr};
    Node *rPtr {nullptr};
    int height { 1 };

    Node (int value)
    : value(value) {}
};
