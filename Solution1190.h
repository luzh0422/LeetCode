//
// Created by luzh on 2021/5/26.
//

#ifndef LEETCODE_SOLUTION1190_H
#define LEETCODE_SOLUTION1190_H

#include <string>

using namespace std;

class Solution1190 {
public:
    Solution1190() {}
    string reverseParentheses(string s);

private:
    void reverseString(string& s, int start, int end);
};


#endif //LEETCODE_SOLUTION1190_H
