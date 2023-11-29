//
// Created by 陆泽辉 on 2022/4/29.
//

#ifndef LEETCODE_LEETCODE427_H
#define LEETCODE_LEETCODE427_H

#include <vector>

using namespace std;

class QuadTreNode {
public:
    bool val;
    bool isLeaf;
    QuadTreNode* topLeft;
    QuadTreNode* topRight;
    QuadTreNode* bottomLeft;
    QuadTreNode* bottomRight;

    QuadTreNode() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    QuadTreNode(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    QuadTreNode(bool _val, bool _isLeaf, QuadTreNode* _topLeft, QuadTreNode* _topRight, QuadTreNode* _bottomLeft, QuadTreNode* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class LeetCode427 {
public:
    QuadTreNode* construct(vector<vector<int>>& grid);

private:
    void construct(vector<vector<int>>& grid, QuadTreNode* node, int rowStart, int rowEnd, int columnStart, int columnEnd);
};


#endif //LEETCODE_LEETCODE427_H
