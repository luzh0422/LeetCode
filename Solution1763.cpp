//
// Created by luzh on 2022/2/1.
//

#include "Solution1763.h"

#include <vector>

string Solution1763::longestNiceSubstring(string s) {
    int n = s.size();
    string ans;
    vector<int> lowerCase(26, 0);
    vector<int> upperCase(26, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            lowerCase[s[i] - 'a']++;
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            upperCase[s[i] - 'A']++;
        }
        vector<int> lowerCaseTemp(lowerCase.begin(), lowerCase.end());
        vector<int> upperCaseTemp(upperCase.begin(), upperCase.end());
        for (int j = 0; j < i; j++) {
            bool equal = true;
            for (int k = 0; k < 26; k++) {
                if (lowerCaseTemp[k] == 0 && upperCaseTemp[k] != 0 || lowerCaseTemp[k] != 0 && upperCaseTemp[k] == 0) {
                    equal = false;
                    break;
                }
            }
            if (equal) {
                string str = s.substr(j, i - j + 1);
                if (str.size() > ans.size()) {
                    ans = str;
                }
            } else {
                if (s[j] >= 'a' && s[j] <= 'z') {
                    lowerCaseTemp[s[j] - 'a']--;
                } else if (s[j] >= 'A' && s[j] <= 'Z') {
                    upperCaseTemp[s[j] - 'A']--;
                }
            }
        }
    }
    return ans;
}
