//
// Created by 陆泽辉 on 2022/12/21.
//

#include "LeetCode1753.h"

#include <queue>
#include <vector>

using namespace std;

int LeetCode1753::maximumScore(int a, int b, int c) {
    priority_queue<int, vector<int>, less<int>> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int ans = 0;
    while (pq.size() >= 2) {
        ans++;
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        first--;
        second--;
        if (first != 0) {
            pq.push(first);
        }
        if (second != 0) {
            pq.push(second);
        }
    }
    return ans;
}
