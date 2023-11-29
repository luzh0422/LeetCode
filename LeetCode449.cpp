//
// Created by 陆泽辉 on 2023/9/4.
//

#include "LeetCode449.h"

string Codec::serialize(TreeNode *root) {
    if (root == NULL) {
        return "";
    }
    string res = to_string(root->val);
    if (root->left) {
        res += ",";
        res += serialize(root->left);
    }
    if (root->right) {
        res += ",";
        res += serialize(root->right);
    }
    return res;
}

TreeNode *Codec::deserialize(string data) {
    if (data == "") {
        return NULL;
    }
    vector<int> dataArr = stringToInt(data);
    TreeNode* root = deserialize(dataArr, 0, dataArr.size() - 1);
    return root;
}

vector<int> Codec::stringToInt(string data) {
    vector<int> res{};
    for (int i = 0; i < data.size(); ) {
        int j = i + 1;
        while (j < data.size() && data[j] != ',') {
            j++;
        }
        int temp = stoi(data.substr(i, j));
        res.push_back(temp);
        i = j + 1;
    }
    return res;
}

TreeNode *Codec::deserialize(vector<int> data, int left, int right) {
    if (left > right) {
        return NULL;
    }
    if (left == right) {
        return new TreeNode(data[left]);
    }
    int rootVal = data[left];
    TreeNode* root = new TreeNode(rootVal);
    int temp = left;
    while (temp < right && data[left] > data[temp + 1]) {
        temp++;
    }
    root->left = deserialize(data, left + 1, temp);
    root->right = deserialize(data, temp + 1, right);
    return root;
}


