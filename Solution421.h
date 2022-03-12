//
// Created by luzh on 2021/5/16.
//

#ifndef LEETCODE_SOLUTION421_H
#define LEETCODE_SOLUTION421_H

#include <vector>

using namespace std;

struct Trie {
    Trie* left = nullptr;
    Trie* right = nullptr;

    Trie() {}
};

class Solution421 {
public:
    Solution421() {}
    int findMaximumXOR(vector<int>& nums);
    void add(int num);
    int check(int num);

private:
    Trie* root = new Trie();
    static constexpr int HIGH_BIT = 30;
};


#endif //LEETCODE_SOLUTION421_H
