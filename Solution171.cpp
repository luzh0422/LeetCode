//
// Created by luzh on 2021/7/30.
//

#include "Solution171.h"
#include "math.h"

int Solution171::titleToNumber(string columnTitle) {
    int size = columnTitle.size();
    int ans = 0;
    for (int i = size - 1; i >= 0; i--) {
        int index = size - 1 - i;
        int temp = pow(26, index);
        int num = columnTitle[i] - 'A' + 1;
        ans += num * temp;
    }
    return ans;
}
