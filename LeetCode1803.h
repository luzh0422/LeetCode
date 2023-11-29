//
// Created by 陆泽辉 on 2023/1/5.
//

#ifndef LEETCODE_LEETCODE1803_H
#define LEETCODE_LEETCODE1803_H

#include <array>
#include <vector>

using namespace std;

struct Trie {
    array<Trie*, 2> son{nullptr, nullptr};
    int sum;
    Trie() : sum(0) {}
};

class LeetCode1803 {
private:
    Trie* root = nullptr;
    static constexpr int HIGH_BIT = 14;

public:
    void add(int num);
    int get(int num, int x);
    int f(vector<int>& nums, int x);
    int countPairs(vector<int>& nums, int low, int high);
};


#endif //LEETCODE_LEETCODE1803_H
