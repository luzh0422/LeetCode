//
// Created by 陆泽辉 on 2023/10/9.
//

#include "LeetCode2578.h"

#include <vector>

using namespace std;

int LeetCode2578::splitNum(int num) {
    vector<int> numArr;
    while (num != 0) {
        numArr.push_back(num % 10);
        num /= 10;
    }
    sort(numArr.begin(), numArr.end());
    int index = 0, n = numArr.size(), num1 = 0, num2 = 0;
    while (index < n - 1) {
        num1 *= 10;
        num1 += numArr[index];
        index++;
        num2 *= 10;
        num2 += numArr[index];
        index++;
    }
    if (index == n - 1) {
        num1 *= 10;
        num1 += numArr[index];
    }
    return num1 + num2;
}
