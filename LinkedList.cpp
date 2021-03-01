//
// Created by Vic on 3/1/2021.
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

    Node *get(int index, Node *currentNode) {
        if (index == 0) {
            return currentNode;
        } else {
            return get(index - 1, currentNode->getNext());
        }
    }

    void set(int index, int value, Node *currentNode) {
        if (index == 0) {
            currentNode->setValue(value);
        } else {
            set(index - 1, value, currentNode->getNext());
        }
    }

    void insert(int index, int value, Node *currentNode) {
        if (index == 1) { // when reaching one Node before the target
            Node *newNode = new Node(value);
            newNode->setNext(currentNode->getNext());
            currentNode->setNext(newNode);
        } else {
            insert(index - 1, value, currentNode->getNext());
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

    Node *get(int index) {
        return get(index, root);
    }

    void set(int index, int value) {
        set(index, value, root);
    }

    void insert(int index, int value) {
        insert(index, value, root);
    }
};

int main() {
    // init
    LinkedList linkedList(5);
    linkedList.add(7);
    linkedList.add(9);
    linkedList.add(12);
    linkedList.add(19);
    linkedList.printAll();

    // get(2)
    cout << "\nGet 2nd item: " << linkedList.get(2)->getValue();

    // set(2, 19)
    cout << "\nset(2, 19)\n";
    linkedList.set(2, 19);
    linkedList.printAll();

    // insert(3, 15)
    cout << "\ninsert(3, 15)\n";
    linkedList.insert(3, 15);
    linkedList.printAll();


    return 0;
}
