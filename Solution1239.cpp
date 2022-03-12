//
// Created by luzh on 2021/6/19.
//

#include "Solution1239.h"
#include <algorithm>

/**
 * 试试二进制状态压缩法；
 * @param arr
 * @return
 */
int Solution1239::maxLength(vector<string> &arr) {
    int size = arr.size();
    vector<int> record(size);
    int ans = 0;
    for (int i = 0; i < size; i++) {
        string s = arr[i];
        int sSize = s.size();
        int temp = 0;
        for (int j = 0; j < sSize; j++) {
            char c = s[j];
            if ((temp & (c - 'a')) != 0) {
                temp = -1;
                break;
            }
            temp |= 1 << (c - 'a');
        }
        record[i] = temp;
        if (temp == -1) {
            continue;
        }
        int curr = arr[i].size();
        ans = max(ans, curr);
        for (int j = 0; j < i; j++) {
            if (record[j] != -1 && (record[i] & record[j]) == 0) {
                curr = arr[i].size() + arr[j].size();
                ans = max(ans, curr);
            }
        }
    }
    return ans;
}
