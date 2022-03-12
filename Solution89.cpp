//
// Created by luzh on 2022/1/8.
//

#include "Solution89.h"

vector<int> Solution89::grayCode(int n) {
    vector<int> ret;
    /**
     * 一次性申请数组内存，避免每次push_back时申请内存，提升执行效率。
     * 同时，这个方法不会修改数组size；
     */
    ret.reserve(1 << n);
    ret.push_back(0);
    for (int i = 1; i <= n; i++) {
        int m = ret.size();
        for (int j = m - 1; j >= 0; j--) {
            ret.push_back(ret[j] | (1 << (i - 1)));
        }
    }
    return ret;
}

