#include <iostream>
#include <vector>
#include <algorithm>

class BinaryHeap {
private:
	std::vector<int> heap_array;
	int get_right_index(int index) {
		return ((2 * index) + 2);
	}

	int get_left_index(int index) {
		return ((2 * index) + 1);
	}

	int get_parent_index(int index) {
		return ((index - 1) / 2);
	}

	void vector_swap(int index1, int index2) {
		int data = heap_array.at(index1);
		heap_array.at(index1) = heap_array.at(index2);
		heap_array.at(index2) = data;
	}

	int max_index(int index1, int index2) {
		if (heap_array.at(index1) > heap_array.at(index2)) {
			return index1;
		}
		else {
			return index2;
		}
	}

public:
	void insert(int data) {
		heap_array.push_back(data);
		int i = heap_array.size() - 1;
		while ((i > 0) and (heap_array.at(get_parent_index(i)) < heap_array.at(i))) {
			vector_swap(get_parent_index(i), i);
			i = get_parent_index(i);
		}
	}

	void remove(int index) {
		if (index > (heap_array.size()-1)) return;
		heap_array.at(index) = *(heap_array.end()-1);
		heap_array.pop_back();
		int i = index;
		if ((i > 0) and (heap_array.at(get_parent_index(i)) < heap_array.at(i))) {
			while ((i > 0) and (heap_array.at(get_parent_index(i)) < heap_array.at(i))) {
				vector_swap(get_parent_index(i), i);
				i = get_parent_index(i);
			}
		}
		else if ((std::max(get_right_index(i), get_left_index(i)) < (heap_array.size())) and heap_array.at(max_index(get_right_index(i), get_left_index(i))) > heap_array.at(i)) {
			while ((std::max(get_right_index(i), get_left_index(i)) < (heap_array.size())) and (heap_array.at(max_index(get_right_index(i), get_left_index(i))) > heap_array.at(i))) {
				vector_swap(max_index(get_right_index(i), get_left_index(i)), i);
				i = max_index(get_right_index(i), get_left_index(i));
			}
		}
		

	}

	void print() {
		for (auto it = heap_array.begin(); it != heap_array.end(); it++) {
			std::cout << *it << " , ";
		}
		std::cout << std::endl;
	}

};


int main()
{
	BinaryHeap heap;
	heap.insert(50);
	heap.insert(20);
	heap.insert(15);
	heap.insert(30);
	heap.insert(60);
	heap.insert(10);
	heap.insert(80);
	heap.insert(5);
	heap.insert(90);
	heap.insert(40);
	heap.insert(70);
	heap.insert(25);
	heap.insert(35);
	heap.print();  

	heap.remove(0);
	heap.remove(5);
	heap.remove(3);
	heap.remove(8);
	heap.remove(4);
	heap.print();   

}

