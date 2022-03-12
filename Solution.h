//
// Created by luzh on 2021/3/14.
//

#ifndef LEETCODE_SOLUTION_H
#define LEETCODE_SOLUTION_H

#include <vector>
struct HashListNode {
    HashListNode(int key, int val) {
        mKey = key;
        mVal = val;
    }
    int mVal;
    int mKey;
    HashListNode* next = NULL;
};

using namespace std;

class Solution {
public:
    Solution() {}
    vector<int> spiralOrder(vector<vector<int>>& matrix);

private:
    void spiralOrder(vector<vector<int>>& matrix, bool left, bool up, bool right, bool down, int row, int column, int width, int height, vector<int>& ans);
};

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap();
    /** value will always be non-negative. */
    void put(int key, int value);
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key);
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key);

private:
    vector<HashListNode* > hashMap = {};
};



#endif //LEETCODE_SOLUTION_H
