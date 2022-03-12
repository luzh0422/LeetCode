//
// Created by luzh on 2021/10/27.
//

#ifndef LEETCODE_SOLUTION301_H
#define LEETCODE_SOLUTION301_H

#include <string>
#include <vector>

using namespace std;

class Solution301 {
public:
    vector<string> removeInvalidParentheses(string s);

private:
    void helper(string s, int last_i, int last_j, vector<char> p, vector<string>& res);
};


#endif //LEETCODE_SOLUTION301_H
