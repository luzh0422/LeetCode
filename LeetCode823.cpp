//
// Created by 陆泽辉 on 2023/8/29.
//

#include "LeetCode823.h"
#include <set>
#include <map>

int LeetCode823::numFactoredBinaryTrees(vector<int> &arr) {
    set<int> s{arr.begin(), arr.end()};
    map<int, int> m{};
    int ans = 0;
    const int mod = 1e9 + 7;
    std::function<int(int)> dfs = [&](int num) -> int {
        long res = 1;
        for (int x : s) {
            if (num % x == 0 && s.count(num / x)) {
                long numx = m.count(x) ? m[x] : dfs(x);
                long numy = m.count(num / x) ? m[num / x] : dfs(num / x);
                res += numx * numy;
                res %= mod;
            }
        }
        m.insert({num, res});
        return res;
    };
    for (int num : s) {
        ans += dfs(num);
        ans %= mod;
    }
    return ans;
}
