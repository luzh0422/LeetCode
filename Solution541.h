//
// Created by luzh on 2021/8/20.
//

#ifndef LEETCODE_SOLUTION541_H
#define LEETCODE_SOLUTION541_H

#include <string>

using namespace std;

class Solution541 {
public:
    string reverseStr(string s, int k);

private:
    void reverseStr(string& s, int start, int end);
};


#endif //LEETCODE_SOLUTION541_H
