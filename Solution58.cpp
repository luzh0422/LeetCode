//
// Created by luzh on 2021/9/21.
//

#include "Solution58.h"

int Solution58::lengthOfLastWord(string s) {
    int n = s.size() - 1;
    while (s[n] == ' ' && n >= 0) {
        n--;
    }
    int ans = 0;
    for (int i = n; i >= 0; i--) {
        if (s[i] == ' ') {
            break;
        }
        ans++;
    }
    return ans;
}
