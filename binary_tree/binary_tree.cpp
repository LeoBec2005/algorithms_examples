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

	int previous_value(int x) {
		Node* temp = head;
		temp = temp->left;

		while (temp->right != nullptr) {
			temp = temp->right;
		}
		return temp->data;
	}

	Node* parent_node(int x) {
		Node* temp = head;
		while (temp->data != x) {
			if (temp->data > x) {
				if (temp->left != nullptr and temp->left->data == x) break;
				temp = temp->left;
			}
			else if (temp->data < x) {
				if (temp->right != nullptr and temp->right->data == x) break;
				temp = temp->right;
			}
		}
		return temp;
	}
public:
	void print_in_order() {
		in_order(head);
		std::cout << std::endl;
	}

	void insert(int x) {
		if (find(x) == 1)return;
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

	void del(int x) {
		if (find(x) == 0)return;
		Node* parent_temp = parent_node(x);
		Node* temp = parent_temp;
		if (temp->data > x) {
			temp = temp->left;
		}
		else if (temp->data < x) {
			temp = temp->right;
		}

		if (temp->left == nullptr and temp->right == nullptr) {
			if (parent_temp->data > x) {
				parent_temp->left = nullptr;
			}
			else if (parent_temp->data < x) {
				parent_temp->right = nullptr;
			}
			delete temp;
		}
		else if (temp->left != nullptr and temp->right == nullptr) {
			if (parent_temp->data > x) {
				parent_temp->left = temp->left;
			}
			else if (parent_temp->data < x) {
				parent_temp->right = temp->left;
			}
			delete temp;
		}
		else if (temp->left == nullptr and temp->right != nullptr) {
			if (parent_temp->data > x) {
				parent_temp->left = temp->right;
			}
			else if (parent_temp->data < x) {
				parent_temp->right = temp->right;
			}
			delete temp;
		}
		else if (temp->left != nullptr and temp->right != nullptr) {
			int previous_data = previous_value(x);
			del(previous_data);
			temp->data = previous_data;
		}
	}

	bool find(int x) {
		Node* temp = head;
		while (true) {
			if (temp == nullptr) {
				return false;
			}
			else if (temp->data == x) {
				return true;
			}
			if (temp->data > x) {
				temp = temp->left;
			}
			else if (temp->data < x) {
				temp = temp->right;
			}
		}
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
	tree_1.insert(16);
	tree_1.insert(13);
	tree_1.insert(30);
	tree_1.insert(9);
	tree_1.insert(20);
	tree_1.insert(19);
	tree_1.insert(18);
	tree_1.print_in_order();

	tree_1.del(9); tree_1.print_in_order();
	tree_1.del(30);	tree_1.print_in_order();
	tree_1.del(3);	tree_1.print_in_order();
	tree_1.del(10);	tree_1.print_in_order();
	tree_1.del(18);	tree_1.print_in_order();
	tree_1.del(2);	tree_1.print_in_order();
}

