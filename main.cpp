#include <iostream>
using namespace std;

class LinkedList;    // Declare for using

class BaseNode {
public:
    string nodeType;
    BaseNode() = default;
    BaseNode(string s): nodeType(s) {}
    ~BaseNode() = default;
};
class Node : public BaseNode {
private:
    int data;
    Node *next;
public:
    Node() = default;
    Node(int a): BaseNode(""), data(a), next(nullptr) {};
    Node(string s, int a): BaseNode(s), data(a), next(nullptr) {};
    ~Node() = default;
    void printNode() { cout << nodeType << "(" << data << ")"; }
    friend class LinkedList;
};


class LinkedList {
private:
    int size;            // size: the size of the Linked list
    Node *first;            // pointing to the first node of the list
public:
    LinkedList(): size(0), first(nullptr) {};
    void PrintList();           // print content of all nodes in the list
    void Push_front(int x);     // add a node at the front of the list
    void Push_front(string s, int x);  // add a node at the front of the list
    void Push_back(int x);      // add a note at the rear of the list
    void Push_back(string s, int x);   // add a note at the rear of the list
    void Clear();
    void Reverse();
    void Delete(string s, int x);
};


void LinkedList::PrintList() {
    // print the constent of the list
    if (first == nullptr) {         // no data in the list
        cout << "List is empty." << endl;
        return;
    }

    Node *current = first;
    while (current != nullptr) {        // Traversing the list and print the content
        current->printNode(); //cout << current->nodeType << "(" << current->data << ") ";
        current = current->next;
    }
    cout << endl;
    cout << "List is of size " << size << endl;
}

void LinkedList::Push_front(int x) {
    // // allocate new memory for the new node
    Node *newNode = new Node(x);    // Note: the parameterized constructor is used
    newNode->next = first;
    first = newNode;
    size += 1;
}

void LinkedList::Push_back(int x) {
    // append new data node at the rear of the list!
    Node *newNode = new Node(x);

    if (first == nullptr) {   // the case that the list is empty
        first = newNode;
    } else { // get to the last position of the list
        Node *current = first;
        while (current->next != nullptr) { // Traversing the list...
            current = current->next;
        }
        current->next = newNode;
    }
    size += 1;
}

// solutions?

void LinkedList::Push_back(string s, int x) {
    // append new data node at the rear of the list!
    Node *newNode = new Node(s, x);

    if (first == nullptr) {   // the case that the list is empty
        first = newNode;
    } else { // get to the last position of the list
        Node *current = first;
        while (current->next != nullptr) { // Traversing the list...
            current = current->next;
        }
        current->next = newNode;
    }
    size += 1;
}

void LinkedList::Push_front(string s, int x) {
    // // allocate new memory for the new node
    Node *newNode = new Node(s, x);    // Note: the parameterized constructor is used
    newNode->next = first;
    first = newNode;
    size += 1;
}

void LinkedList::Delete(string s, int x) {
    Node *current = first, *previous = nullptr;
    while (current != nullptr && current->data != x) {  // traversing
        previous = current;
        current = current->next;
        /* update the size here? */
    }
    if (current == nullptr) {   // either can't find the node or the list is empty
        cout << x << " is not found in list." << endl;
    } else if (current == first) {  // the node to delete is the first node of the list
        first = current->next;
        delete current;
        current = nullptr;
        /* update the size here */
    } else {    // the other case:
        previous->next = current->next;
        delete current;
        current = nullptr;
        /* update the size here */
    }
    size --;
}
void LinkedList::Clear() {
    while (first != nullptr) { // Traversal
        Node *current = first;
        first = first->next;
        delete current;
        current = nullptr;
    }
}
void LinkedList::Reverse() {
    if (first != nullptr && first->next != nullptr) {
        Node *previous = nullptr, *current = first, *preceding = first->next;
        while (preceding != nullptr) {
            current->next = previous;
            previous = current;
            current = preceding;
            preceding = preceding->next;
        }   // until preceding gets to nullptr
        current->next = previous;  // now current is at the last node
        first = current;         // update first to be current
    }
}

int main() {
    LinkedList list;
    list.PrintList();    // so far the list is empty
    list.Push_back("B", 5);
    list.Push_back("A", 3);
    list.Push_front("C", 9);
    list.Push_front("N", 7);
    list.Delete("C", 9);
    list.Reverse();
    list.PrintList();
    list.Clear();
    list.PrintList();
    return 0;
}


