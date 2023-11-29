//
// Created by 陆泽辉 on 2023/9/3.
//

#include "LeetCode1921.h"
#include <queue>

int LeetCode1921::eliminateMaximum(vector<int> &dist, vector<int> &speed) {
//    auto cmp = [&](tuple<int, int, int>& v1, tuple<int, int, int>& v2) -> bool {
//        auto [d1, s1, index1] = v1;
//        auto [d2, s2, index2] = v2;
//        if (d1 < d2) {
//            return true;
//        } else if (d1 == d2 && s1 < s2) {
//            return true;
//        } else {
//            return false;
//        }
//    };
//    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> pq(cmp);
//    auto clear = [&]() {
//        while(!pq.empty()) {
//            pq.pop();
//        }
//    };
//    int n = dist.size();
//    for (int i = 0; i < n; i++) {
//        pq.push({dist[i], speed[i], i});
//    }
//    int res = 0;
//    vector<int> tag(n, 0);
//    while (!pq.empty()) {
//        auto [d, s, index] = pq.top();
//        pq.pop();
//        res++;
//        tag[index] = 1;
//        clear();
//        int temp = 0;
//        for (int i = 0; i < n; i++) {
//            if (tag[i] == 0) {
//                dist[i] = dist[i] - speed[i];
//                if (dist[i] < 0) {
//                    temp++;
//                }
//                if (temp > 1) {
//                    break;
//                }
//                pq.push({dist[i], speed[i], i});
//            }
//        }
//    }
//    return res;

    int n = dist.size();
    vector<int> steps(n, 0);
    for (int i = 0; i < n; i++) {
        steps[i] = (dist[i] + speed[i] - 1) / speed[i];
    }
    std::sort(steps.begin(), steps.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i >= steps[i]) {
            break;
        }
        res++;
    }
    return res;
}
