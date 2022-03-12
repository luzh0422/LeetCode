//
// Created by luzh on 2021/6/30.
//

#ifndef LEETCODE_SOLUTIONOFFER37_H
#define LEETCODE_SOLUTIONOFFER37_H

#include "TreeNode.h"

#include <vector>
#include <string>
#include <list>

using namespace std;

class SolutionOffer37 {
public:
    string serialize(TreeNode* root);
    TreeNode* deserialize(string data);

private:
    void rserialize(TreeNode* root, string& str);
    TreeNode* rdeserialize(list<string>& data);
//    TreeNode* deserialize(vector<string>& data, int& index);
//    vector<string> stringToVectorInt(string& s);
};


#endif //LEETCODE_SOLUTIONOFFER37_H
