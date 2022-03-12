//
// Created by luzh on 2021/4/20.
//

#include "Solution28.h"
#include <vector>

using namespace std;

/**
 * 注意每次利用size函数求长度有性能消耗；
 * KMP算法；
 * @param haystack
 * @param needle
 * @return
 */
int Solution28::strStr(string haystack, string needle) {
//    if (needle == "") {
//        return 0;
//    }
//    int m = haystack.size();
//    int n = needle.size();
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (haystack[i + j] != needle[j]) {
//                break;
//            }
//            if (j == n - 1) {
//                return i;
//            }
//        }
//    }
//    return -1;
    int n = haystack.size(), m = needle.size();
    if (m == 0) {
        return 0;
    }
    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && needle[i] != needle[j]) {
            j = pi[j - 1];
        }
        if (needle[i] == needle[j]) {
            j++;
        }
        pi[i] = j;
    }
    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && haystack[i] != needle[j]) {
            j = pi[j - 1];
        }
        if (haystack[i] == needle[j]) {
            j++;
        }
        if (j == m) {
            return i - m + 1;
        }
    }
    return -1;
}
