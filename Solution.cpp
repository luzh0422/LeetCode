//
// Created by luzh on 2021/3/14.
//

#include "Solution.h"

MyHashMap::MyHashMap() {
    hashMap.resize(100);
    for (int i = 0; i < 100; i++) {
        hashMap[i] = new HashListNode(-1, -1);
    }
}

void MyHashMap::put(int key, int value) {
    int hashkey = key % 100;
    HashListNode* node = hashMap[hashkey];
    while (node->next != NULL) {
        if (node->mKey == key) {
            node->mVal = value;
            return;
        }
        node = node->next;
    }
    if (node->mKey == key) {
        node->mVal = value;
        return;
    }
    node->next = new HashListNode(key, value);
}

int MyHashMap::get(int key) {
    int hashKey = key % 100;
    HashListNode* node = hashMap[hashKey];
    while (node != NULL) {
        if (node->mKey == key) {
            return node->mVal;
        }
        node = node->next;
    }
    return -1;
}

void MyHashMap::remove(int key) {
    int hashKey = key % 100;
    if (hashMap[hashKey] == NULL) {
        return;
    }
    HashListNode* node = hashMap[hashKey]->next ;
    HashListNode* parent = hashMap[hashKey];
    while (node != NULL) {
        if (node->mKey == key) {
            parent->next = node->next;
            break;
        }
        parent = node;
        node = node->next;
    }
}

vector<int> Solution::spiralOrder(vector<vector<int>> &matrix) {
    vector<int> ans = {};
    int height = matrix.size();
    int width = matrix[0].size();
    this->spiralOrder(matrix, false, false, true, false, 0, 0, width, height, ans);
    return ans;
}

void Solution::spiralOrder(vector<vector<int>> &matrix, bool left, bool up, bool right, bool down, int row, int column, int width, int height, vector<int> &ans) {
    if (width == 0 || height == 0) {
        return;
    }
    int step = 0;
    if (left) {
        /**
         * 从右往左走；
         */
        while (step < width) {
            ans.push_back(matrix[row][column - step]);
            step++;
        }
        spiralOrder(matrix, false, true, false, false, row - 1, column - step + 1, width, height - 1, ans);
    } else if (right) {
        /**
         * 从左往右走；
         */
        while (step < width) {
            ans.push_back(matrix[row][column + step]);
            step++;
        }
        spiralOrder(matrix, false, false, false, true, row + 1, column + step - 1, width, height - 1, ans);
    } else if (up) {
        /**
         * 从下往上走；
         */
        while (step < height) {
            ans.push_back(matrix[row - step][column]);
            step++;
        }
        spiralOrder(matrix, false, false, true, false, row - step + 1, column + 1, width - 1, height, ans);
    } else if (down) {
        /**
         * 从上往下走；
         */
        while (step < height) {
            ans.push_back(matrix[row + step][column]);
            step++;
        }
        spiralOrder(matrix, true, false, false, false, row + step - 1, column - 1, width - 1, height, ans);
    }
}
