//
// Created by luzh on 2022/1/31.
//

#include "Solution1342.h"

int Solution1342::numberOfSteps(int num) {
    int ans = 0;
    while (num != 0) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = num - 1;
        }
        ans++;
    }
    return ans;
}
