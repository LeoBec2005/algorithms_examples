#include <iostream>

struct Deque {
    int map_size = 5;
    int block_size = 5;
    int start_block = map_size / 2;
    int finish_block = map_size / 2;
    int start_offset = block_size /2;
    int finish_offset = (block_size / 2)+1;
    int** map = new int*[map_size]();

    Deque() {
        map[start_block] = new int[block_size]();
    }

    void print() {
        int i = start_block;
        int j = start_offset;
        while (j <= finish_offset and i <= finish_block) {
            while (j < block_size) {
                std::cout << map[i][j] << " , ";
                j++;
            }
            j = 0;
            i++;
        }
        std::cout << "end" << std::endl;
    }

    void push_front(int x) {
        map[start_block][start_offset] = x;
        start_offset--;

        if (start_offset < 0) {
            start_block--;
            start_offset = block_size - 1;
            map[start_block] = new int[block_size]();
        }
    }

    void push_back(int x) {
        map[finish_block][finish_offset] = x;
        finish_offset++;

        if (finish_offset >= block_size) {
            finish_block++;
            finish_offset = 0;
            map[finish_block] = new int[block_size]();
        }
    }

    void pop_front() {
        start_offset++;

        if (start_offset > block_size) {
            start_offset = 0;
            delete[] map[start_block];
            start_block++;
        }
    }

    void pop_back() {
        finish_offset--;

        if (finish_offset < 0) {
            finish_offset = block_size - 1;
            delete[] map[finish_block];
            finish_block--;
        }
    }
};

int main()
{
    Deque deque_1;

    deque_1.push_front(2);
    deque_1.push_front(4);
    deque_1.push_front(6);
    deque_1.push_front(7);
    deque_1.push_back(8);
    deque_1.push_back(1);
    deque_1.push_back(3);
    deque_1.push_back(5);
    deque_1.push_back(5);
    deque_1.push_back(4);
    deque_1.print();

    deque_1.pop_back();
    deque_1.print();
    deque_1.pop_back();
    deque_1.pop_back();
    deque_1.pop_back();
    deque_1.pop_back();
    deque_1.pop_front();
    deque_1.pop_front();
    deque_1.pop_front();
    deque_1.print();



}


