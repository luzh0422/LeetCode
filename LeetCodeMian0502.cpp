//
// Created by 陆泽辉 on 2023/3/2.
//

#include "LeetCodeMian0502.h"
#include <numeric>

string LeetCodeMian0502::printBin(double num) {
    int index = 0;
    string res = "0.";
    while (index < 32) {
        num = 2 * num;
        int temp = floor(num);
        num -= temp;
        res += to_string(temp);
        if (num == 0) {
            break;
        }
        index++;
    }
    if (num == 0) {
        return res;
    } else {
        return "ERROR";
    }
}
