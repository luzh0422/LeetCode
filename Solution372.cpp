//
// Created by luzh on 2021/12/5.
//

#include "Solution372.h"
#include "math.h"

int Solution372::superPow(int a, vector<int> &b) {
    int n = b.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int step = n - i - 1;
        int count = b[i] * pow(10, step);
        int temp = a;
        for (int i = 0; i < count; i++) {
            temp = temp * a;
            temp %= 1337;
        }
        ans += temp;
        ans %= 1337;
    }
    return ans;
}


