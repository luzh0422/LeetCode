//
// Created by luzh on 2022/1/10.
//

#include "Solution306.h"

bool Solution306::isAdditiveNumber(string num) {
    int firstIndex = 0;
    int firstLength = 1;
    int n = num.size();
    while (firstIndex + firstLength < n - 1) {
        int secondIndex = firstIndex + firstLength;
        int secondLength = 1;
        while (secondIndex + secondLength <= n - 1) {
            if (isAdditiveNumber(num, firstIndex, firstLength, secondIndex, secondLength)) {
                return true;
            }
            secondLength += 1;
        }
        firstLength += 1;
    }
    return false;
}

bool Solution306::isAdditiveNumber(string num, int firstIndex, int firstLength, int secondIndex, int secondLength) {
    string firstNumStr = num.substr(firstIndex, firstLength);
    string secondNumStr = num.substr(secondIndex, secondLength);
    if (secondNumStr[0] == '0' && secondNumStr.size() > 1 || firstNumStr[0] == '0' && firstNumStr.size() > 1) {
        return false;
    }
    float firstNum = stof(firstNumStr);
    float secondNum = stof(secondNumStr);
    float thirdNum1 = firstNum + secondNum;
    int thirdIndex = secondIndex + secondLength;
    int thirdLength = 1;
    float thirdNum2 = 0;
    while (thirdIndex + thirdLength <= num.size()) {
        string thirdNum2Str = num.substr(thirdIndex, thirdLength);
        if (thirdNum2Str[0] == '0' && thirdNum2Str.size() > 1) {
            return false;
        }
        thirdNum2 = stof(thirdNum2Str);
        if (thirdNum2 > thirdNum1) {
            return false;
        }
        if (thirdNum2 == thirdNum1) {
            if (thirdIndex + thirdLength == num.size()) {
                return true;
            } else {
                return isAdditiveNumber(num, secondIndex, secondLength, thirdIndex, thirdLength);
            }
        }
        thirdLength++;
    }
    return false;
}
