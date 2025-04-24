//
// Created by luzehui on 25-1-8.
//

#include "LeetCode2264.h"

string LeetCode2264::largestGoodInteger(std::string num) {
    int curr = -1, n = num.size();
    string res = "";
    for (int i = 0; i < n - 2; i++) {
        if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
            if (num[i] - '0' > curr) {
                curr = num[i] - '0';
                res = num.substr(i, 3);
            }
        }
    }
    return res;
}
