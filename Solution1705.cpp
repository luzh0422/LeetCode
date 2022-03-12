//
// Created by luzh on 2021/12/24.
//

#include "Solution1705.h"
#include <queue>

typedef pair<int, int> pii;

/**
 * 每次都先吃腐烂日期短的水果；同时，每一天，要把腐烂的水果去除掉；
 * 模型：先将每天 先 把存储篮子中腐烂的水果去除掉；
 *      将每天的水果先放到一个 存储篮子中，同时记录水果的过期日期、和数量；
 *      判断篮子中是否还有没有 未腐烂 的水果，吃掉过期日期最近的一个；
 *      最后，判断篮子中还有多少水果，依次吃掉即可。
 * @param apples
 * @param days
 * @return
 */
int Solution1705::eatenApples(vector<int> &apples, vector<int> &days) {
    int ans = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int n = apples.size();
    int i = 0; // i代表当天的天数；
    while (i < n) {
        /**
         * 去除当天已经腐烂的水果；
         */
        while (!pq.empty() && pq.top().first <= i) {
            pq.pop();
        }
        int rottenDay = i + days[i]; // 腐烂日期；
        int count = apples[i]; // 苹果数量；
        if (count > 0) {
            pq.emplace(rottenDay, count);
        }
        /**
         * 取出腐烂日期最近的水果，吃一个；
         */
        if (!pq.empty()) {
            pii curr = pq.top();
            pq.pop();
            curr.second--;
            if (curr.second != 0) {
                pq.emplace(curr.first, curr.second);
            }
            ans++;
        }
        i++;
    }
    /**
     * 摘水果日期过去后，仍可将剩余的水果吃掉；
     */
    while (!pq.empty()) {
        /**
         * 去除当天已经腐烂的水果；
         */
        while (!pq.empty() && pq.top().first <= i) {
            pq.pop();
        }
        if (pq.empty()) {
            break;
        }
        pii curr = pq.top();
        pq.pop();
        int num = min(curr.first - i, curr.second);
        ans += num;
        i += num;
    }
    return ans;
}
