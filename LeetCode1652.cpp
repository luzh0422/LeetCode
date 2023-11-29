//
// Created by 陆泽辉 on 2022/9/24.
//

#include "LeetCode1652.h"

vector<int> LeetCode1652::decrypt(vector<int> &code, int k) {
    int n = code.size();
    vector<int> ret(n, 0);
    for (int i = 0; i < n; i++) {
        auto temp = 0;
        for (int j = 1; j <= abs(k); j++) {
            if (k > 0) {
                temp += code[(i + j) % n];
            } else {
                temp += code[(i - j + n) % n];
            }
        }
        ret[i] = temp;
    }
    return ret;
}
