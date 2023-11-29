//
// Created by luzehui on 2023/10/25.
//

#include "LeetCode2520.h"

int LeetCode2520::countDigits(int num) {
    int temp = num, ans = 0;
    while (temp != 0) {
        int delta = temp % 10;
        temp /= 10;
        if (num % delta == 0) {
            ans++;
        }
    }
    return ans;
}
