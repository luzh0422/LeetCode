//
// Created by luzh on 2021/12/14.
//

#include "Solution630.h"
#include <queue>

/**
 * 模型：对课程按 lastDay 进行排序；
 *      先修 lastDay 靠前的课程；
 *      如果 当前时长， 已经超过 所修课程的 lastDay；
 *      判断 这个课程 的duration 和 优先队列中 最长duration 课程的duration进行比较；如果小于它，则可以先修这个课程，
 *      因为这样 所需的总时长最短；
 * @param courses
 * @return
 */
int Solution630::scheduleCourse(vector<vector<int>> &courses) {
    sort(courses.begin(), courses.end(), [](vector<int>& course1, vector<int>& course2) -> bool {
        return course1[1] < course2[1];
    });
    priority_queue<int, vector<int>, less<int>> q = {}; // 大顶堆；
    int total = 0;
    int ans = 0;
    for (int i = 0; i < courses.size(); i++) {
        vector<int> &course = courses[i];
        int t1 = course[0], l1 = course[1];
        if (total + t1 < l1) {
            total += t1;
            q.push(t1);
            ans++;
        } else if (!q.empty() && q.top() > t1) {
            total -= q.top() - t1;
            q.pop();
            q.push(t1);
        }
    }
    return ans;
}
