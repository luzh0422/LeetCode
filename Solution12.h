//
// Created by luzh on 2021/5/14.
//

#ifndef LEETCODE_SOLUTION12_H
#define LEETCODE_SOLUTION12_H

#include <string>

using namespace std;

class Solution12 {
public:
    Solution12() {}
    string intToRoman(int num);

private:
    string intToRomanHelper(int& num);
};


#endif //LEETCODE_SOLUTION12_H
