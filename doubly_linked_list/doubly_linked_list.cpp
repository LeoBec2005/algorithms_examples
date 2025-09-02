#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node* forward = nullptr;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void print() {
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            std::cout << temp->data << " , ";
        }
        std::cout << std::endl;

        for (Node* temp = tail; temp != nullptr; temp = temp->forward) {
            std::cout << temp->data << " , ";
        }
        std::cout << std::endl;
    }

    void push_front(int x) {
        Node* new_node = new Node;
        new_node->data = x;
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        }
        else {
            Node* temp = head;
            head = new_node;
            temp->forward = new_node;
            new_node->next = temp;
        }
    }

    void push_back(int x) {
        Node* new_node = new Node;
        new_node->data = x;
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        }
        else {
            Node* temp = tail;
            tail = new_node;
            temp->next = new_node;
            new_node->forward = temp;
        }
    }

};

int main() {
    List list_1;
    list_1.push_front(2);
    list_1.push_front(4);
    list_1.push_front(6);
    list_1.push_front(1);
    list_1.push_back(0);
    list_1.push_back(7);
    list_1.push_back(8);
    list_1.push_back(9);
    list_1.print();




}