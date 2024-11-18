//
// Created by luzehui on 2024/5/16.
//

#include "zijie1.h"

vector<int> zijie1::getBinaryCount(int x) {
    vector<int> res(x + 1, 0);
    auto getBinaryCountHelper = [](int num) -> int {
        int temp = 0;
        while (num != 0) {
            if (num % 2 == 1) {
                temp++;
            }
            num /= 2;
        }
    };
    for (int i = 1; i <= x; i++) {
        res[i] = getBinaryCountHelper(i);
    }
    return res;
}
