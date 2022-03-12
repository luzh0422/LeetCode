//
// Created by luzh on 2021/5/23.
//

#include "Solution1707.h"
#include <map>

/**
 * 常规思路，但是超时；
 * @param nums
 * @param queries
 * @return
 */
//vector<int> Solution1707::maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
//    map<int, int> cache;
//    for (int i = 0; i < nums.size(); i++) {
//        if (cache.count(nums[i])) {
//            continue;
//        } else {
//            cache.insert(map<int, int>::value_type(nums[i], 1));
//        }
//    }
//    vector<int> ans(queries.size());
//    for (int i = 0; i < queries.size(); i++) {
//        int xi = queries[i][0];
//        int mi = queries[i][1];
//        int temp = 0;
//        for (auto it = cache.begin(); it != cache.end(); it++) {
//            int first = it->first;
//            if (first > mi) {
//                break;
//            }
//            temp = max(temp, xi ^ it->first);
//        }
//        ans[i] = temp;
//    }
//    return ans;
//}

void Tire::insert(int val) {
    Tire* node = this;
    for (int i = L - 1; i >= 0; --i) {
        int bit = (val >> i) & 1;
        if (node->children[bit] == nullptr) {
            node->children[bit] = new Tire();
        }
        node = node->children[bit];
    }
}

int Tire::getMaxXor(int val) {
    int ans = 0;
    Tire* node = this;
    for (int i = L - 1; i >= 0; --i) {
        int bit = (val >> i) & 1;
        if (node->children[bit ^ 1] != nullptr) {
            ans |= 1 << i;
            bit ^= 1;
        }
        node = node->children[bit];
    }
    return ans;
}

vector<int> Solution1707::maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
    sort(nums.begin(), nums.end());
    int numQ = queries.size();
    for (int i = 0; i < numQ; i++) {
        queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), [](vector<int>& x, vector<int>& y) -> bool {
        return x[1] < y[1];
    });
    vector<int> ans(numQ);
    Tire* t = new Tire();
    int idx = 0, n = nums.size();
    for (auto& q: queries) {
        int x = q[0], m = q[1], qid = q[2];
        while (idx < n && nums[idx] <= m) {
            t->insert(nums[idx]);
            ++idx;
        }
        if (idx == 0) { // 字典树为空
            ans[qid] = -1;
        } else {
            ans[qid] = t->getMaxXor(x);
        }
    }
    return ans;
}
