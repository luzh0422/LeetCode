//
// Created by luzh on 2021/11/14.
//

#ifndef LEETCODE_SOLUTION677_H
#define LEETCODE_SOLUTION677_H

#include <string>
#include <unordered_map>

using namespace std;

struct TreeNode {
    TreeNode() {};
    unordered_map<char, TreeNode*> children = {};
    int val = 0;
};

class Solution677 {
public:
    Solution677();

    void insert(string key, int val);

    int sum(string prefix);

private:
    TreeNode* root = new TreeNode();
};


#endif //LEETCODE_SOLUTION677_H
