//
// Created by 陆泽辉 on 2023/2/8.
//

#ifndef LEETCODE_LEETCODE1233_H
#define LEETCODE_LEETCODE1233_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

struct Tire {
    string name_ = "";
    unordered_map<string, Tire*> children;
    bool leaveNode = false;
    Tire(string name = ""): name_(name) {}
};

class LeetCode1233 {
public:
    vector<string> removeSubfolders(vector<string>& folder);

private:
    vector<string> parseFolder(string& folder);
};


#endif //LEETCODE_LEETCODE1233_H
