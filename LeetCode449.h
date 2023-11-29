//
// Created by 陆泽辉 on 2023/9/4.
//

#ifndef LEETCODE_LEETCODE449_H
#define LEETCODE_LEETCODE449_H

#include <string>
#include <vector>
#include "TreeNode.h"

using namespace std;

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root);

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data);

private:
    vector<int> stringToInt(string data);
    TreeNode* deserialize(vector<int> data, int left, int right);
};

#endif //LEETCODE_LEETCODE449_H
