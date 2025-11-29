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

public:
void insert(int data){
    heap_array.push_back(data);
}

};


int main()
{
    
}

