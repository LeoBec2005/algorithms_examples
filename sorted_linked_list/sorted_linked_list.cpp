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
};


int main()
{

}


