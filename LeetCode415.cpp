//
// Created by 陆泽辉 on 2023/7/17.
//

#include "LeetCode415.h"

string LeetCode415::addStrings(string num1, string num2) {
    int n = num1.size() - 1, m = num2.size() - 1;
    int temp = 0;
    string res = "";
    while (n >= 0 && m >= 0) {
        int curr = (num1[n] - '0') + (num2[m] - '0') + temp;
        temp = curr / 10;
        curr %= 10;
        res.insert(res.begin(), curr + '0');
        n--;
        m--;
    }
    while (n >= 0) {
        int curr = (num1[n] - '0') + temp;
        temp = curr / 10;
        curr %= 10;
        res.insert(res.begin(), curr + '0');
        n--;
    }
    while (m >= 0) {
        int curr = (num2[m] - '0') + temp;
        temp = curr / 10;
        curr %= 10;
        res.insert(res.begin(), curr + '0');
        m--;
    }
    if (temp > 0) {
        res.insert(res.begin(), temp + '0');
    }
    return res;
}
