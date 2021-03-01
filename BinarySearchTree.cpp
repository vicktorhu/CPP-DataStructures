//
// Created by Vic on 3/1/2021.
// NOT FINISHED YET
//

#include <iostream>

using namespace std;

class Node {
private:
    int value;
    Node *next = NULL;
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

    Node *getNext() const {
        return next;
    }

    void setNext(Node *next) {
        Node::next = next;
    }
};

class LinkedList {
private:
    Node *root;

    void add(int value, Node *currentNode) {
        if (currentNode->getNext() == NULL) {
            currentNode->setNext(new Node(value));
        } else {
            add(value, currentNode->getNext());
        }
    }

    void printAll(Node *currentNode) {
        cout << "(" << currentNode->getValue() << ")";
        if (currentNode->getNext() != NULL) {
            cout << "->";
            printAll(currentNode->getNext());
        }
    }

public:
    LinkedList(int rootValue) {
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
    LinkedList linkedList(5);
    linkedList.add(7);
    linkedList.add(9);
    linkedList.add(12);
    linkedList.add(19);
    linkedList.printAll();
    return 0;
}
