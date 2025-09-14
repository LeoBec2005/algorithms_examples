#include <iostream>

struct Node {
	int data;
	Node* prev = nullptr;
	Node* next = nullptr;
};

struct SortedList {
	Node* head = nullptr;
	Node* tail = nullptr;

    ~SortedList(){
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

    void insert(int x) {
        Node* new_node = new Node;
        new_node->data = x;

        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            return;
        }

        Node* temp = head;
        while(temp != nullptr and temp->data < x) {
            temp = temp->next;
        }

        if (temp == head) {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }
        else if (temp == tail->next) {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
        else {
            new_node->prev = temp->prev;
            new_node->prev->next = new_node;
            temp->prev = new_node;
            new_node->next = temp;
        }
    }
};


int main()
{
    SortedList list_1;
    list_1.insert(4);
    list_1.insert(7);
    list_1.insert(1);
    list_1.insert(0);
    list_1.insert(3);
    list_1.print_forward();
    list_1.print_backward();

}


