/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
#include <vector>
#include <cstddef>
using namespace std;
int main(int argc, char* argv[])
{
    Node nodes[8] = {Node(1, NULL), Node(2, NULL), Node(3, NULL), Node(4, NULL), Node(5, NULL), Node(6, NULL), Node(7, NULL), Node(8, NULL)};
    for (int i = 0; i < 7; i++) {
        nodes[i].next = &nodes[i+1];
    }
    Node* in = &nodes[0];
    Node* odds = NULL;
    Node* evens = NULL;
    Node* curr = in;
    while (curr != NULL) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
    split(in, odds, evens);
    cout << "Input: ";
    curr = in;
    while (curr != NULL) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
    cout << "Odds: ";
    curr = odds;
    while (curr != NULL) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
    cout << "Evens: ";
    curr = evens;
    while (curr != NULL) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
    return 0;
}
