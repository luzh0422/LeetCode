//
// Created by 陆泽辉 on 2022/7/27.
//

#include "LeetCode592.h"
#include <vector>

using namespace std;

string LeetCode592::fractionAddition(string expression) {
    vector<int> numerators, denominators;
    disassembleString(expression, numerators, denominators);
    int numerator = numerators[0];
    int denominator = denominators[0];
    int n = numerators.size();
    for (int i = 1; i < n; i++) {
        int numerator1 = numerators[i];
        int denominator1 = denominators[i];
        int leastCommonDivisor = theLeastCommonDivisor(denominator, denominator1);
        int greatestCommonMultiple = theGreatestCommonMultiple(denominator, denominator1, leastCommonDivisor);
        int multiple = greatestCommonMultiple / denominator;
        int multiple1 = greatestCommonMultiple / denominator1;
        numerator = numerator * multiple + numerator1 * multiple1;
        denominator = greatestCommonMultiple;
    }
    int leastCommonDivisor = 1;
    if (numerator != 0 && denominator != 0) {
        leastCommonDivisor = theLeastCommonDivisor(numerator, denominator);
    } else {
        leastCommonDivisor = denominator;
    }
    numerator /= leastCommonDivisor;
    denominator /= leastCommonDivisor;
    return to_string(numerator) + "/" + to_string(denominator);
}

void LeetCode592::disassembleString(string &expression, vector<int> &numberators, vector<int> &denominators) {
    bool isNegative = false;
    int num = 0;
    int n = expression.size();
    for (int i = 0; i < n; i++) {
        if (expression[i] == '/') {
            if (isNegative) {
                num = -num;
            }
            numberators.emplace_back(num);
            isNegative = false;
            num = 0;
        } else if (expression[i] == '+') {
            if (isNegative) {
                num = -num;
            }
            denominators.emplace_back(num);
            isNegative = false;
            num = 0;
        } else if (expression[i] == '-') {
            if (num != 0) {
                if (isNegative) {
                    num = -num;
                }
                denominators.emplace_back(num);
            }
            isNegative = true;
            num = 0;
        } else {
            num = num * 10 + expression[i] - '0';
        }
    }
    if (num != 0) {
        if (isNegative) {
            num = -num;
        }
        denominators.emplace_back(num);
    }
    return;
}

int LeetCode592::theLeastCommonDivisor(int num1, int num2) {
    int minVal = min(abs(num1), abs(num2));
    int maxVal = max(abs(num1), abs(num2));
    if (maxVal % minVal == 0) {
        return minVal;
    }
    return theLeastCommonDivisor(minVal, maxVal % minVal);
}

int LeetCode592::theGreatestCommonMultiple(int num1, int num2, int leastCommonDivisor) {
    return abs(num1 * num2) / leastCommonDivisor;
}

