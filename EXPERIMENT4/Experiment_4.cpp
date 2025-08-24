#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() { head = nullptr; }

    void insertBegin(int val) {
        Node* n = new Node(val);
        if (head != nullptr) {
            n->next = head;
            head->prev = n;
        }
        head = n;
    }

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = n; return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    void deleteBegin() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void deleteEnd() {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp->next) temp = temp->next;
        if (temp->prev) temp->prev->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};


class CircularLinkedList {
public:
    Node* head;
    CircularLinkedList() { head = nullptr; }

    void insertBegin(int val) {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = n;
            n->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            n->next = head;
            temp->next = n;
            head = n;
        }
    }

    void insertEnd(int val) {
        Node* n = new Node(val);
        if (head == nullptr) {
            head = n;
            n->next = head;
        }
        else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = n;
            n->next = head;
        }
    }

    void deleteBegin() {
        if (head == nullptr) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        Node* last = head;
        while (last->next != head) last = last->next;
        head = head->next;
        last->next = head;
        delete temp;
    }

    void deleteEnd() {
        if (head == nullptr) return;
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != head) temp = temp->next;
        Node* del = temp->next;
        temp->next = head;
        delete del;
    }

    void display() {
        if (head == nullptr) { cout << endl; return; }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};


int main() {
    DoublyLinkedList dl;
    dl.insertBegin(10);
    dl.insertEnd(20);
    dl.insertBegin(5);
    dl.display();
    dl.deleteBegin();
    dl.deleteEnd();
    dl.display();

    CircularLinkedList cl;
    cl.insertBegin(10);
    cl.insertEnd(20);
    cl.insertBegin(5);
    cl.display();
    cl.deleteBegin();
    cl.deleteEnd();
    cl.display();
}