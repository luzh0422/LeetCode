//
// Created by luzh on 2022/1/10.
//

#ifndef LEETCODE_SOLUTION306_H
#define LEETCODE_SOLUTION306_H

#include <string>

using namespace std;

class Solution306 {
public:
    bool isAdditiveNumber(string num);

private:
    bool isAdditiveNumber(string num, int firstIndex, int firstLength, int secondIndex, int secondLength);
};


#endif //LEETCODE_SOLUTION306_H
