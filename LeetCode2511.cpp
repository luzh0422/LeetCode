//
// Created by 陆泽辉 on 2023/9/2.
//

#include "LeetCode2511.h"

int LeetCode2511::captureForts(vector<int> &forts) {
    int n = forts.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        int j = i - 1;
        int left = 0, right = 0;
        while (j >= 0) {
            if (forts[j] == 1) {
                left = 0;
                break;
            } else if (forts[j] == -1) {
                left = i - j - 1;
                break;
            }
            j--;
        }
        j = i + 1;
        while (j < n) {
            if (forts[j] == 1) {
                right = 0;
                break;
            } else if (forts[j] == -1) {
                right = j - i - 1;
                break;
            }
            j++;
        }
        res = max({res, left, right});
    }
    return res;
}
