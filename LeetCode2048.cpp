//
// Created by luzehui on 2023/12/12.
//

#include "LeetCode2048.h"
#include <unordered_map>
#include <vector>

int LeetCode2048::nextBeautifulNumber(int n) {
    for (int i = n + 1; i <= 1e6; i++) {
        if (isBeautifulNumber(i)) {
            return i;
        }
    }
    return -1;
}

bool LeetCode2048::isBeautifulNumber(int n) {
    std::vector<int> uM(10, 0);
    while (n != 0) {
        int num = n % 10;
        uM[num]++;
        if (uM[num] > num) {
            return false;
        }
        n /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (uM[i] > 0 && uM[i] != i) {
            return false;
        }
    }
    return true;
}
