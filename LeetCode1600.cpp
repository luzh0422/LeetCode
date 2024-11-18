//
// Created by luzehui on 2024/4/7.
//

#include "LeetCode1600.h"

typedef unordered_map<string, MyTreeNode*> stringMyTreeNodeValueType;

ThroneInheritance::ThroneInheritance(std::string kingName) {
    root = new MyTreeNode(kingName);
    familyMap.insert(stringMyTreeNodeValueType::value_type(kingName, root));
}

void ThroneInheritance::birth(std::string parentName, std::string childName) {
    auto node = familyMap[parentName];
    auto childNode = new MyTreeNode(childName);
    node->children.push_back(childNode);
    familyMap.insert(stringMyTreeNodeValueType::value_type(childName, childNode));
}

void ThroneInheritance::death(std::string name) {
    familyMap[name]->dead = true;
}

vector<string> ThroneInheritance::getInheritanceOrder() {
    vector<string> res;
    preorder(root, res);
    return res;
}

void ThroneInheritance::preorder(MyTreeNode *node, vector<std::string> &res) {
    if (!node) {
        return;
    }
    if (!node->dead) {
        res.push_back(node->_name);
    }
    for (auto child : node->children) {
        preorder(child, res);
    }
}
