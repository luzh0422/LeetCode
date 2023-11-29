//
// Created by 陆泽辉 on 2023/1/12.
//

#ifndef LEETCODE_LEETCODE1807_H
#define LEETCODE_LEETCODE1807_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class LeetCode1807 {
public:
    string evaluate(string s, vector<vector<string>>& knowledge);

private:
    void evaluate(string& s, unordered_map<string, string>& dictionary);
};


#endif //LEETCODE_LEETCODE1807_H
