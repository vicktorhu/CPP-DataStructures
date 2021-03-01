//
// Created by Vic on 3/1/2021.
//
//

#include <iostream>

using namespace std;

class Node {
private:
    int value;
    Node *left = NULL, *right = NULL;
public:
    Node(int val) {
        value = val;
    }

    int getValue() const {
        return value;
    }

    void setValue(int value) {
        Node::value = value;
    }

    Node *getLeft() const {
        return left;
    }

    void setLeft(Node *left) {
        Node::left = left;
    }

    Node *getRight() const {
        return right;
    }

    void setRight(Node *right) {
        Node::right = right;
    }
};

class BinarySearchTree {
private:
    Node *root;

    void add(int value, Node *currentNode) {
        // no double value on the entire tree
        if (currentNode->getValue() < value) {
            if (currentNode->getRight() == NULL) {
                currentNode->setRight(new Node(value));
            } else {
                add(value, currentNode->getRight());
            }
        }
        if (currentNode->getValue() > value) {
            if (currentNode->getLeft() == NULL) {
                currentNode->setLeft(new Node(value));
            } else {
                add(value, currentNode->getLeft());
            }
        }
    }

    void printAll(Node *currentNode) {
        if (currentNode->getLeft() != NULL) {
            printAll(currentNode->getLeft());
        }
        cout << currentNode->getValue() << " ";
        if (currentNode->getRight() != NULL) {
            printAll(currentNode->getRight());
        }
    }

public:
    BinarySearchTree(int rootValue) {
        root = new Node(rootValue);
    }

    void add(int value) {
        add(value, root);
    }

    void printAll() {
        printAll(root);
    }
};

int main() {
    BinarySearchTree binarySearchTree(10);
    binarySearchTree.add(5);
    binarySearchTree.add(15);
    binarySearchTree.add(7);
    binarySearchTree.add(12);
    binarySearchTree.printAll();
    return 0;
}
