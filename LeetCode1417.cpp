//
// Created by 陆泽辉 on 2022/8/11.
//

#include "LeetCode1417.h"

#include <vector>

string LeetCode1417::reformat(string s) {
    vector<char> nums(10, 0);
    vector<char> chars(26, 0);
    int numberCount = 0, charCount = 0;
    for (char& c: s) {
        if (c >= '0' && c <= '9') {
            numberCount++;
            nums[c - '0']++;
        } else {
            charCount++;
            chars[c - 'a']++;
        }
    }
    string ret = "";
    if (abs(numberCount - charCount) <= 1) {
        int numIndex = 0, charIndex = 0, tag = numberCount > charCount ? 0 : 1;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (tag == 0) {
                while (numIndex < 10 && nums[numIndex] == 0) {
                    numIndex++;
                }
                ret += '0' + numIndex;
                nums[numIndex]--;
            } else {
                while (charIndex < 26 && chars[charIndex] == 0) {
                    charIndex++;
                }
                ret += 'a' + charIndex;
                chars[charIndex]--;
            }
            tag ^= 1;
        }
    }
    return ret;
}
