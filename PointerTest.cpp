//
// Created by Vic on 3/1/2021.
// To be deleted later
//
#include <iostream>
using namespace std;

class Node {
public:
    Node(int val){
        value = val;
    }

public:
    int value;
    Node* next;
};

int main() {
    Node * node1p = new Node(5);
    Node node1 = *node1p;
    node1.next = new Node(7);
    cout << node1.value << node1.next->value;
    return 0;
}
