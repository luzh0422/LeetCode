//
// Created by luzh on 2021/10/7.
//

#include "Solution434.h"

int Solution434::countSegments(string s) {
    int space = 1;
    int ans = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != ' ') {
            space = 0;
        } else {
            if (space == 0) {
                ans++;
            }
            space = 1;
        }
    }
    return space == 0 ? ans + 1 : ans;
}
