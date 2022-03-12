//
// Created by luzh on 2022/1/28.
//

#include "Solution1996.h"

int Solution1996::numberOfWeakCharacters(vector<vector<int>> &properties) {
    std::sort(properties.begin(), properties.end(), [](const vector<int>& arr1, const vector<int>& arr2) -> bool {
        if (arr1[0] > arr2[0]) {
            return true;
        } else if (arr1[0] == arr2[0]) {
            return arr1[1] < arr2[1];
        } else {
            return false;
        }
    });
    int n = properties.size();
    int MAXDefence = INT_MIN;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (MAXDefence > properties[i][1]) {
            ans++;
        }
        MAXDefence = max(MAXDefence, properties[i][1]);
    }
    return ans;
}
