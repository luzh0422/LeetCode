//
// Created by 陆泽辉 on 2023/2/8.
//

#include "LeetCode1233.h"

vector<string> LeetCode1233::removeSubfolders(vector<string> &folder) {
    std::sort(folder.begin(), folder.end(), [](string& f1, string& f2) -> bool {
        return f1.size() < f2.size();
    });
    Tire* root = new Tire();
    vector<string> res = {};
    for (auto& f : folder) {
        vector<string> names = parseFolder(f);
        auto node = root;
        int n = names.size();
        bool tag = true;
        for (int i = 0; i < n; i++) {
            if (node->children.count(names[i])) {
                if (node->children[names[i]]->leaveNode) {
                    tag = false;
                }
            } else {
                auto temp = new Tire(names[i]);
                node->children.insert(unordered_map<string, Tire*>::value_type(names[i], temp));
            }
            node = node->children[names[i]];
            if (i == n - 1) {
                node->leaveNode = true;
            }
        }
        if (tag) {
            res.push_back(f);
        }
    }
    return res;
}

vector<string> LeetCode1233::parseFolder(string &folder) {
    int n = folder.size();
    vector<string> res = {};
    int i = 1, j = i + 1;
    for (;i < n; i++) {
        j = i + 1;
        for (; j < n; j++) {
            if (folder[j] == '/') {
                break;
            }
        }
        if (i != j) {
            res.push_back(folder.substr(i, j - i));
        }
        i = j;
    }
    if (i < n) {
        res.push_back(folder.substr(i, n - i));
    }
    return res;
}
