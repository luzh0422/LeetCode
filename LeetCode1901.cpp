//
// Created by luzehui on 2023/12/19.
//

#include "LeetCode1901.h"

vector<int> LeetCode1901::findPeakGrid(vector<vector<int>> &mat) {
    auto indexOfMax = [&](vector<int>& a) -> int {
        return max_element(a.begin(), a.end()) - a.begin();
    };
    int left = 0, right = mat.size() - 2;
    while (left <= right) {
        int mid = (left + right) / 2;
        int index = indexOfMax(mat[mid]);
        if (mat[mid][index] > mat[mid + 1][index]) {
            right = mid - 1; // 峰顶行号 <= i
        } else {
            left = mid + 1; // 峰顶行号 > i
        }
    }
    return {left, indexOfMax(mat[left])};
}
