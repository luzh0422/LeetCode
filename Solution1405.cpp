//
// Created by luzh on 2022/2/7.
//

#include "Solution1405.h"
#include <queue>
#include <vector>

string Solution1405::longestDiverseString(int a, int b, int c) {
    vector<pair<int, char>> pool = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
    auto cmp = [](pair<int, char>& p1, pair<int, char>& p2) -> bool {
        return p1.first > p2.first;
    };
    std::sort(pool.begin(), pool.end(), cmp);
    bool hasNext = a != 0 || b != 0 || c != 0;
    string ans = "";
    while (hasNext) {
        hasNext = false;
        for (int i = 0; i < 3; i++) {
            int n = ans.size();
            if (n >= 2 && ans[n - 2] == pool[i].second && ans[n - 1] == pool[i].second) {
                continue;
            } else if (pool[i].first > 0) {
                ans += pool[i].second;
                pool[i].first--;
                hasNext = true;
                std::sort(pool.begin(), pool.end(), cmp);
                break;
            }
        }
    }
    return ans;
}

