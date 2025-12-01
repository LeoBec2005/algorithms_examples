#include <iostream>
#include <vector>

class BinaryHeap {
private:
std::vector<int> heap_array;
int get_right_index(int index){
    return ((2*index)+2);
}

int get_left_index(int index){
    return ((2*index)+1);
}

int get_parent_index(int index){
    return ((index-1)/2);
}

void vector_swap(int index1,int index2) {
    int data = heap_array.at(index1);
    heap_array.at(index1) = heap_array.at(index2);
    heap_array.at(index2) = data;
}

public:
void insert(int data){
    heap_array.push_back(data);
    int data_index = heap_array.size()-1;
    while ((data_index > 0) and (heap_array.at(get_parent_index(data_index)) < heap_array.at(data_index))) {
            vector_swap(get_parent_index(data_index), data_index);
            data_index = get_parent_index(data_index);
    }
}

void print() {
    for (auto it = heap_array.begin(); it != heap_array.end(); it++) {
        std::cout << *it << " , ";
    }
    std::cout<<std::endl;
}

};


int main()
{
    BinaryHeap heap;
    heap.insert(3);
    heap.insert(5);
    heap.insert(1);
    heap.insert(0);
    heap.insert(10);
    heap.insert(2);

    heap.print();

}

