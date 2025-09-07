#include <iostream>

struct Node {
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    ~List(){
        if (head == nullptr) return;
        Node* temp = head;
        while (temp != nullptr) {
            Node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        std::cout << "list destroyed!"<<std::endl;
    } 

    void print_forward() const {
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            std::cout << temp->data << " , ";
        }
        std::cout << std::endl;
    }

    void print_backward() const {
        for (Node* temp = tail; temp != nullptr; temp = temp->prev) {
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
            temp->prev = new_node;
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
            new_node->prev = temp;
        }
    }

    void pop_back() {
        if (head == nullptr) return;
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    void pop_front() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
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
    list_1.print_backward();
    list_1.print_forward();

    list_1.pop_back();
    list_1.pop_back();
    list_1.pop_front();
    list_1.pop_front();
    list_1.print_backward();
    list_1.print_forward();

}