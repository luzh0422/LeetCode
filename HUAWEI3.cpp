//
// Created by luzh on 2021/10/23.
//

#include "HUAWEI3.h"
#include <string>
#include <algorithm>

//vector<int> stringToNums(string s) {
//    int curr = 0;
//    vector<int> ans = {};
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] ==',') {
//            ans.push_back(curr);
//            curr = 0;
//        } else {
//            curr = curr * 10 + (s[i] - '0');
//        }
//    }
//    return ans;
//}

int HUAWEI3::shortestNum(vector<int> &nums) {
    /**
     * 棍子的长度必在 [maxNum, sumNum] 之间；
     * 然后找到[maxNum, sumNum]之间满足条件的最小长度；
     */
    int maxNum = 0;
    int sumNum = 0;
    for (auto value : nums) {
        sumNum += value;
        maxNum = max(maxNum, value);
    }
    int n = nums.size();
    for (int i = maxNum; i <= sumNum; i++) {
        /**
         * i代表每根木棍的长度；
         */
        vector<int> visit(n, 0);
        if (sumNum % i != 0) continue;
        int num = sumNum / i; // 有多少根木棍；
        if (dfs(0, num, 0, i, nums, visit)) {
            return i;
        }
    }
    return 0;
}

/**
 * 通过回溯判断木头是否能满足条件；
 */
bool HUAWEI3::dfs(int cnt, int num, int currLen, int length, vector<int> &nums, vector<int> &visit) {
    if (cnt == num) {
        /**
         * 符合木棍的数量与预期相符，则返回true；
         */
        return true;
    }
    int n = visit.size();
    for (int i = 0; i < n; i++) {
        if (visit[i]) {
            continue;
        }
        visit[i] = 1;
        if (currLen + nums[i] == length) {
            /**
             * 判断在当前木棍满足条件的基础上，是否其他木棍也满足条件；
             */
            if (dfs(cnt + 1, num, 0, length,nums, visit)) {
                return true;
            } else {
                visit[i] = 0;
            }
        } else if (currLen + nums[i] < length) {
            if (dfs(cnt, num, currLen + nums[i], length,nums, visit)) {
                return true;
            } else {
                visit[i] = 0;
                while (nums[i] == nums[i + 1]) {
                    i++;
                }
            }
        } else {
            visit[i] = 0;
        }
    }
    return false;
}
