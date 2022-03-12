//
// Created by luzh on 2021/6/20.
//

#ifndef LEETCODE_SOLUTION1600_H
#define LEETCODE_SOLUTION1600_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    vector<Node* > children = {};
    string _name;
    bool alive = true;
    Node(string name) : _name(name) {};
};

class ThroneInheritance {
public:
    ThroneInheritance(string kingName);

    void birth(string parentName, string childName);

    void death(string name);

    vector<string> getInheritanceOrder();

private:
    Node* root = nullptr;
    unordered_map<string, Node*> record = {};
};

#endif //LEETCODE_SOLUTION1600_H
