//
// Created by 陆泽辉 on 2023/1/9.
//

#include "LeetCode1806.h"
#include <vector>

using namespace std;

int LeetCode1806::reinitializePermutation(int n) {
    vector<int> arr = {};
    for (int i = 0; i < n; i++) {
        arr.push_back(i);
    }
    vector<int> tmp = arr;
    int res = 0;
    for (int i = 0; i < n; i++) {
        res++;
        vector<int> tmp1 = {};
        for (int i = 0; i < n; i += 2) {
            tmp1.push_back(tmp[i]);
        }
        for (int i = 1; i < n; i += 2) {
            tmp1.push_back(tmp[i]);
        }
        tmp = tmp1;
        if (tmp == arr) {
            break;
        }
    }
    return res;
}
