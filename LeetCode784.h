//
// Created by 陆泽辉 on 2022/10/30.
//

#ifndef LEETCODE_LEETCODE784_H
#define LEETCODE_LEETCODE784_H

#include <string>
#include <vector>
#include <set>

using namespace std;

class LeetCode784 {
public:
    vector<string> letterCasePermutation(string s);

private:
    void backtrack(string& s, set<string>& ret, int curr);
};


#endif //LEETCODE_LEETCODE784_H
