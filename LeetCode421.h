//
// Created by luzehui on 2023/11/4.
//

#ifndef LEETCODE_LEETCODE421_H
#define LEETCODE_LEETCODE421_H

#include <vector>

using namespace std;

struct Tire {
    Tire* left = nullptr;
    Tire* right = nullptr;
    Tire() : left(nullptr), right(nullptr) {}
};

class LeetCode421 {
public:
    int findMaximumXOR(vector<int>& nums);

private:
    Tire* root = new Tire();
    const int HIGHBIT = 30;
    void add(int num);
    int check(int num);
};


#endif //LEETCODE_LEETCODE421_H
