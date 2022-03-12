//
// Created by luzh on 2021/9/14.
//

#include "Solution524.h"

/**
 * 时间复杂度：O(d(m + n)); d是dictionary的长度，m是s的长度，n是dictionary所有字符串的平均长度；
 * @param s
 * @param dictionary
 * @return
 */
string Solution524::findLongestWord(string s, vector<string> &dictionary) {
    string res = "";
    int n = dictionary.size();
    int sSize = s.size();
    for (int i = 0; i < n; i++) {
        int j = 0, k = 0;
        string dict = dictionary[i];
        int dictSize = dict.size();
        /**
         * 利用双指针判断一个字符串是否是另一个字符串子串的办法；
         */
        while (j < sSize && k < dictSize) {
            if (s[j] == dict[k]) {
                k++;
            }
            j++;
        }
        if (k == dictSize) {
            res = res.size() > dict.size() || res.size() == dict.size() && res < dict ? res : dict;
        }
    }
    return res;
}
