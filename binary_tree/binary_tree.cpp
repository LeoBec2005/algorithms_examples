#include <iostream>

struct Node {
    int data;
    Node* right = nullptr;
    Node* left = nullptr;
};

class BinaryTree {
private:
    Node* head = nullptr;

    void in_order(Node* next) {
        if (next == nullptr)return;
        in_order(next->left);
        std::cout << next->data << " , ";
        in_order(next->right);
    }

public:
    void print_in_order() {
        in_order(head);
        std::cout<<std::endl;
    }

    void insert(int x) {
        Node* new_node = new Node;
        new_node->data = x;
        if (head == nullptr) {
            head = new_node;
        }
        else {
            Node* temp = head;
            while (true) {
                if (temp->data > x) {
                    if (temp->left == nullptr) break;
                    temp = temp->left;
                }
                else if (temp->data < x) {
                    if (temp->right == nullptr) break;
                    temp = temp->right;
                }
            }
            if (temp->data > x) {
                temp->left = new_node;
            }
            else if (temp->data < x) {
                temp->right = new_node;
            }
        }

    }

    bool find(int x) {

    }


};


int main()
{
    BinaryTree tree_1;
    tree_1.insert(10);
    tree_1.insert(3);
    tree_1.insert(2);
    tree_1.insert(5);
    tree_1.insert(6);
    tree_1.insert(1);
    tree_1.insert(0);

    tree_1.print_in_order();
}

