//
// Created by luzehui on 25-2-25.
//

#ifndef LEETCODE_LEETCODE2502_H
#define LEETCODE_LEETCODE2502_H

#include <vector>

using namespace std;

class Allocator {
public:
    Allocator(int n);

    int allocate(int size, int mID);

    int freeMemory(int mID);

private:
    vector<int> memory;
};

#endif //LEETCODE_LEETCODE2502_H
