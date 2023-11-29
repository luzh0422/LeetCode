//
// Created by 陆泽辉 on 2022/5/4.
//

#include "LeetCode1823.h"
#include <queue>

using namespace std;

/**
 * 利用队列实现循环排队模拟；
 * @param n
 * @param k
 * @return
 */
int LeetCode1823::findTheWinner(int n, int k) {
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }
    while (q.size() > 1) {
        for (int i = 0; i < k - 1; i++) {
            q.emplace(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}
