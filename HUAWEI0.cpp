//
// Created by luzh on 2021/12/25. //

#include "HUAWEI0.h"
#include <set>

using namespace std;

int HUAWEI0::longestNoRepeat(string s) {
    int n = s.size();
    int ans = 0;
    set<char> record = {};
    /**
     * initialize;
     */
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (!record.count(c)) {
            record.emplace(c);
        } else {
            record.clear();
            record.emplace(c);
            for (int j = i - 1; j >= 0; j--) {
                if (!record.count(s[j])) {
                    record.emplace(s[j]);
                } else {
                    break;
                }
            }
        }
        ans = max(ans, (int)record.size());
    }
    return ans;
}

