//
// Created by 陆泽辉 on 2023/3/25.
//

#include "LeetCode1574.h"

int LeetCode1574::findLengthOfShortestSubarray(vector<int> &arr) {
    int n = arr.size();
    int prefixIndex = 0, suffixIndex = n - 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1]) {
            prefixIndex++;
        } else {
            break;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] <= arr[i + 1]) {
            suffixIndex--;
        } else {
            break;
        }
    }
    if (prefixIndex >= suffixIndex) {
        return 0;
    }
    int temp = suffixIndex - prefixIndex - 1;
    vector<vector<int>> cache(n, vector<int>(n, -1));
    int count = findLengthOfShortestSubarray(arr, 0, prefixIndex, suffixIndex, n - 1, cache);
    return count + temp;
}

int LeetCode1574::findLengthOfShortestSubarray(vector<int> &arr, int prefixLeft, int prefixRight, int suffixLeft, int suffixRight, vector<vector<int>>& cache) {
    if (prefixRight < prefixLeft || suffixRight < suffixLeft) {
        return 0;
    }
    if (arr[prefixRight] <= arr[suffixLeft]) {
        return 0;
    }
    if (cache[prefixRight][suffixLeft] != -1) {
        return cache[prefixRight][suffixLeft];
    }
    int prefixCount = findLengthOfShortestSubarray(arr, prefixLeft, prefixRight - 1, suffixLeft, suffixRight, cache) + 1;
    int suffixCount = findLengthOfShortestSubarray(arr, prefixLeft, prefixRight, suffixLeft + 1, suffixRight, cache) + 1;
    int prefixAndSuffixCount = findLengthOfShortestSubarray(arr, prefixLeft, prefixRight - 1, suffixLeft + 1, suffixRight, cache) + 2;

    int res = min(prefixCount, min(suffixCount, prefixAndSuffixCount));
    cache[prefixRight][suffixLeft] = res;
    return res;
}
