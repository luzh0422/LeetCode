//
// Created by luzh on 2021/9/8.
//

#include "Solution502.h"

#include <queue>

int Solution502::findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
    typedef pair<int, int> pii;
    int n = profits.size();
    int curr = 0;
    /**
     * 优先队列的用法可以记一下。优先队列内部的实现就是利用堆的方式，因此在做堆排序问题时，可以考虑用这种数据结构。
     */
    priority_queue<int, vector<int>, less<int>> pq;
    vector<pii> arr;

    /**
     * 这个也是map按value排序的方法；
     */
    for (int i = 0; i < n; ++i) {
        arr.push_back({capital[i], profits[i]});
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < k; ++i) {
        /**
         * 将满足条件的项目的项目都加入优先队列中；
         */
        while (curr < n && arr[curr].first <= w) {
            pq.push(arr[curr].second);
            curr++;
        }
        /**
         * 从优先队列中依次取出最大值，作为结果；
         */
        if (!pq.empty()) {
            /**
             * 原来有一种节省内存的方法，是通过使用传入函数的变量；
             */
            w += pq.top();
            pq.pop();
        } else {
            break;
        }
    }
    /**
     * 利用传入的变量作为结果，避免重新申请变量，节省内存；
     */
    return w;
}
