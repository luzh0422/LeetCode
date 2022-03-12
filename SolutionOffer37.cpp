//
// Created by luzh on 2021/6/30.
//

#include "SolutionOffer37.h"

#include <list>

//#include <stack>
//
//TreeNode * SolutionOffer37::deserialize(string data) {
//    vector<string> nodeVals = stringToVectorInt(data);
//    if (nodeVals.size() == 0) {
//        return nullptr;
//    }
//    int i = 0;
//    return deserialize(nodeVals, i);
//}
//
//TreeNode * SolutionOffer37::deserialize(vector<string>& data, int &index) {
//    if (data[index] == "null") {
//        return nullptr;
//    }
//    if (index == data.size()) {
//        index--;
//        return nullptr;
//    }
//    TreeNode* root = new TreeNode(stoi(data[index]));
//    root->left = deserialize(data, ++index);
//    root->right = deserialize(data, ++index);
//    return root;
//}
//
//string SolutionOffer37::serialize(TreeNode *root) {
//    if (root == nullptr) {
//        return "[]";
//    }
//    string ans = "";
//    ans = "[" + to_string(root->val);
//    std::stack<TreeNode*> stk;
//    stk.push(root);
//    while (!stk.empty()) {
//        TreeNode* node = stk.top();
//        stk.pop();
//        if (node->left == nullptr) {
//            ans += ",null";
//        } else {
//            ans += "," + to_string(node->left->val);
//            stk.push(node->left);
//        }
//        if (node->right == nullptr) {
//            ans += ",null";
//        } else {
//            ans += "," + to_string(node->right->val);
//            stk.push(node->right);
//        }
//    }
//    ans += "]";
//    return ans;
//}
//
//vector<string> SolutionOffer37::stringToVectorInt(string& s) {
//    int sSize = s.size();
//    vector<string> ans = {};
//    for (int i = 1; i < sSize; ) {
//        if (s[i] == ']') {
//            break;
//        }
//        int j = i;
//        for (; j < sSize; j++) {
//            if (s[j] == ',' || s[j] == ']') {
//                break;
//            }
//        }
//        string temp = s.substr(i, j - i);
//        ans.push_back(temp);
//        i = j + 1;
//    }
//    return ans;
//}

string SolutionOffer37::serialize(TreeNode *root) {
    string ret;
    rserialize(root, ret); // 序列化的过程主要是靠这个函数；
    return ret;
}

void SolutionOffer37::rserialize(TreeNode *root, string &str) {
        if (root == nullptr) {
        str += "null,";
    } else {
        /**
         * dfs
         */
        str += to_string(root->val) + ',';
        rserialize(root->left, str);
        rserialize(root->right, str);
    }
}

TreeNode * SolutionOffer37::deserialize(string data) {
    list<string> dataArray;
    string str;
    for (auto& ch: data) {
        if (ch == ',') {
            dataArray.push_back(str);
            str.clear();
        } else {
            str.push_back(ch);
        }
    }
    if (!str.empty()) {
        dataArray.push_back(str);
        str.clear();
    }
    return rdeserialize(dataArray);
}

TreeNode * SolutionOffer37::rdeserialize(list<string>& dataArray) {
    if (dataArray.front() == "None" || dataArray.front() == "null") {
        dataArray.erase(dataArray.begin());
        return nullptr;
    }
    if (dataArray.empty()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(dataArray.front()));
    dataArray.erase(dataArray.begin());
    root->left = rdeserialize(dataArray);
    root->right = rdeserialize(dataArray);
    return root;
}
