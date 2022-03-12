//
// Created by luzh on 2021/9/12.
//

#ifndef LEETCODE_SOLUTION678_H
#define LEETCODE_SOLUTION678_H

#include <string>
#include <stack>

using namespace std;

class Solution678 {
public:
    bool checkValidString(string s);
private:
    bool checkValidString(string s, int leftBraveCount, int start, int end);
};


#endif //LEETCODE_SOLUTION678_H
