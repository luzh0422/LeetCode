//
// Created by 陆泽辉 on 2022/6/19.
//

#include "LeetCode508.h"

vector<int> LeetCode508::findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> uM = {};
    findFrequentTreeSum(root, uM);
    vector<pair<int, int>> temp(uM.begin(), uM.end());
    std::sort(temp.begin(), temp.end(), [](pair<int, int> &p1, pair<int, int> &p2) -> bool {
        return p1.second > p2.second;
    });
    vector<int> ret = {};
    int maxVal = 0;
    for (auto it = temp.begin(); it != temp.end(); ++it) {
        if (it->second >= maxVal) {
            maxVal = it->second;
            ret.push_back(it->first);
        } else {
            break;
        }
    }
    return ret;
}

int LeetCode508::findFrequentTreeSum(TreeNode *root, unordered_map<int, int> &uM) {
    if (root == nullptr) {
        return 0;
    }
    int left = findFrequentTreeSum(root->left, uM);
    int right = findFrequentTreeSum(root->right, uM);
    int val = left + right + root->val;
    if (uM.count(val)) {
        uM[val]++;
    } else {
        uM.insert(unordered_map<int, int>::value_type (val, 1));
    }
    return val;
}
