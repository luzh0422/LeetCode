//
// Created by 陆泽辉 on 2022/7/27.
//

#ifndef LEETCODE_LEETCODE592_H
#define LEETCODE_LEETCODE592_H

#include <string>

using namespace std;

class LeetCode592 {
public:
    string fractionAddition(string expression);

private:
    int theLeastCommonDivisor(int num1, int num2);
    int theGreatestCommonMultiple(int num1, int num2, int leastCommonDivisor);
    void disassembleString(string& expression, vector<int>& numberators, vector<int>& denominators);
};


#endif //LEETCODE_LEETCODE592_H
