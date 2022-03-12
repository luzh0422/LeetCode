//
// Created by luzh on 2021/7/7.
//

#include "Solution1711.h"

#include <map>

int Solution1711::countPairs(vector<int> &deliciousness) {
    int size = deliciousness.size();
    if (size < 2) {
        return 0;
    }
    map<int, int> uM;
    for (int i = 0; i < deliciousness.size(); i++) {
        if (uM.count(deliciousness[i])) {
            uM[deliciousness[i]] ++;
        } else {
            uM[deliciousness[i]] = 1;
        }
    }
    std::sort(deliciousness.begin(), deliciousness.end());
    int biggestNum = deliciousness[size - 1];
    int biggerNum = deliciousness[size - 2];
    /**
     * 最大的2的阶乘；
     */
    int boundary = biggerNum + biggestNum;
    long ans = 0;
    const int deltaAns = 1000000007;
    for (auto it = uM.begin(); it != uM.end(); it++) {
        int num = it->first;
        int numCount = it->second;
        int index = 1;
        while (index <= boundary) {
            if (index >= 2 * num) {
                int delta = index - num;
                if (delta == num) {
                    long temp = long(numCount) * long(numCount - 1) / 2;
                    ans += temp;
                } else if (uM.count(delta)) {
                    int deltaCount = uM[delta];
                    ans += numCount * deltaCount;
                }
                ans %= deltaAns;
            }
            index = index * 2;
        }
//        int firstNum = it->first;
//        int firstCount = it->second;
//        if (firstNum > 0 && (firstNum & (firstNum - 1)) == 0) {
//            ans += firstCount * (firstCount - 1) / 2;
//            ans %= deltaAns;
//        }
//        auto jt = it;
//        jt++;
//        for (; jt != uM.end(); jt++) {
//            int secondNum = jt->first;
//            int secondCount = jt->second;
//            int sumNum = firstNum + secondNum;
//            if ((sumNum & (sumNum - 1)) == 0) {
//                ans += firstCount * secondCount;
//                ans %= deltaAns;
//            }
//        }
    }
    return ans;
}
