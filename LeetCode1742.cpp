//
// Created by 陆泽辉 on 2022/11/23.
//

#include "LeetCode1742.h"
#include <vector>

using namespace std;

int LeetCode1742::countBalls(int lowLimit, int highLimit) {
    vector<int> counts(45, 0);
    int ret = 0;
    for (int i = lowLimit; i <= highLimit; i++) {
        int x = i;
        int digit = 0;
        while (x >= 0) {
            digit += x % 10;
            x /= 10;
        }
        counts[digit]++;
        ret = max(ret, counts[digit]);
    }
    return ret;
}
