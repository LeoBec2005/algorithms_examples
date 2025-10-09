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
		if (find(x) == 0)return x;
		Node* temp = head;
		while (true) {
			if ((temp->left != nullptr and temp->left->data == x) or temp->data == x) {
				break;
			}
			else if (temp->right != nullptr and temp->right->data == x) {
				break;
			}
			if (temp->data > x) {
				temp = temp->left;
			}
			else if (temp->data < x) {
				temp = temp->right;
			}
		}

		if (temp->left != nullptr and temp->left->left == nullptr and temp->left->data == x) {
			return temp->data;
		}
		else if (temp->right != nullptr and temp->right->left == nullptr and temp->right->data == x) {
			return temp->data;
		}

		if (temp->left->data == x) {
			temp = temp->left;
		}
		else if (temp->right->data == x) {
			temp = temp->right;
		}

		temp = temp->left;

		while (temp->right != nullptr) {
			temp = temp->right;
		}
		return temp->data;
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
		Node* temp = head;
		while (temp->data != x) {
			if (temp->data > x) {
				temp = temp->left;
			}
			else if (temp->data < x) {
				temp = temp->right;
			}
		}

		if (temp->left == nullptr and temp->right == nullptr) {
			delete temp;
			temp = nullptr;
		}
		else if (temp->left != nullptr and temp->right == nullptr) {
			Node* temp_2 = temp->left;
			temp->left = temp_2->left;
			temp->data = temp_2->data;
			delete temp_2;
		}
		else if (temp->left == nullptr and temp->right != nullptr) {
			Node* temp_2 = temp->right;
			temp->right = temp_2->right;
			temp->data = temp_2->data;
			delete temp_2;
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

	std::cout << tree_1.find(10) << std::endl;
	std::cout << tree_1.find(2) << std::endl;
	std::cout << tree_1.find(5) << std::endl;
	std::cout << tree_1.find(12) << std::endl;
	std::cout << tree_1.find(13) << std::endl;

	tree_1.del(30);
	tree_1.del(9);
	tree_1.del(3);
	tree_1.del(10);
	tree_1.del(18);
	tree_1.del(2);
	tree_1.print_in_order();
}

