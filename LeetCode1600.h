//
// Created by luzehui on 2024/4/7.
//

#ifndef LEETCODE_LEETCODE1600_H
#define LEETCODE_LEETCODE1600_H

#include <string>
#include <vector>
#include <list>

using namespace std;

struct MyTreeNode {
    string _name;
    MyTreeNode(string name) : _name(name) {};
    vector<MyTreeNode*> children{};
    bool dead = false;
};

class ThroneInheritance {
public:
    ThroneInheritance(string kingName);

    void birth(string parentName, string childName);

    void death(string name);

    vector<string> getInheritanceOrder();

private:
    void preorder(MyTreeNode* node, vector<string>& res);
    MyTreeNode* root = nullptr;
    unordered_map<string, MyTreeNode*> familyMap;
};


#endif //LEETCODE_LEETCODE1600_H
