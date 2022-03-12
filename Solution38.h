//
// Created by luzh on 2021/10/15.
//

#ifndef LEETCODE_SOLUTION38_H
#define LEETCODE_SOLUTION38_H

#include <string>

using namespace std;

class Solution38 {
public:
    string countAndSay(int n);

private:
    int countString(string& s, char c, int index);
};


#endif //LEETCODE_SOLUTION38_H
