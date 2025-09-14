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
        clear();
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
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
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
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void pop_back() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    void pop_front() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    bool find(int x) {
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            if (temp->data == x) return 1;
        }
        return 0;
    }

    void clear() {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp != nullptr) {
            Node* temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
        head = nullptr;
        tail = nullptr;
    }

    int list_length() {
        int length = 0;
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            length++;
        }
        return length;
    }

    void insert(int pos, int x) {
        if (pos > list_length() or pos < 0) {
            std::cout << "the position is not valid!" << std::endl;
            return;
        }
        Node* new_node = new Node;
        new_node->data = x;
        Node* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        
        if (temp == head) {
            push_front(x);
        }
        else if (temp == tail->next) {
            push_back(x);
        }
        else {
            new_node->prev = temp->prev;
            new_node->prev->next = new_node;
            temp->prev = new_node;
            new_node->next = temp;
        }
    }

    void erase(int pos) {
        if (pos >= list_length() or pos < 0) {
            std::cout << "the position is not valid!" << std::endl;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }

        if (temp == head) {
            pop_front();
        }
        else if (temp == tail) {
            pop_back();
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

};

int main() {
    List list_1;

    //push front and back test
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

    //pop front and back test
    list_1.pop_back();
    list_1.pop_back();
    list_1.pop_front();
    list_1.pop_front();
    list_1.print_forward();

    //insert test
    list_1.insert(2, 10);
    list_1.print_forward();
    list_1.insert(3, 11);
    list_1.print_forward();
    list_1.insert(0, 12);
    list_1.print_forward();
    list_1.insert(7, 13);
    list_1.print_forward();

    //erase test
    list_1.erase(4);
    list_1.print_forward();
    list_1.erase(0);
    list_1.print_forward();
    list_1.erase(5);
    list_1.print_forward();
    list_1.erase(2);
    list_1.print_forward();

    //list length test
    std::cout << list_1.list_length() << std::endl;

    //find test
    std::cout << list_1.find(4) << std::endl;
    std::cout << list_1.find(2) << std::endl;
    std::cout << list_1.find(6) << std::endl;
    std::cout << list_1.find(100) << std::endl;
    
}