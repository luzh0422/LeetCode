//
// Created by luzehui on 25-2-25.
//

#include "LeetCode2502.h"

Allocator::Allocator(int n) {
    memory.resize(n, 0);
}

int Allocator::allocate(int size, int mID) {
    size_t n = memory.size();
    int index = 0;
    while (index < n) {
        if (memory[index] == 0) {
            int j = index;
            while (j - index < size && j < n && memory[j] == 0) {
                j++;
            }
            if (j - index == size) {
                while (index < j) {
                    memory[index] = mID;
                    index++;
                }
                return index - size;
            }
            index = j;
        }
        index++;
    }
    return -1;
}

int Allocator::freeMemory(int mID) {
    size_t n = memory.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (memory[i] == mID) {
            memory[i] = 0;
            res++;
        }
    }
    return res;
}
