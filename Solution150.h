//
// Created by luzh on 2021/3/20.
//

#ifndef LEETCODE_SOLUTION150_H
#define LEETCODE_SOLUTION150_H

#include <string>
#include <vector>

using namespace std;

class Solution150 {
public:
    Solution150() {};
    int evalRPN(vector<string>& tokens);

private:
    int strToNum(string str);
};


#endif //LEETCODE_SOLUTION150_H
