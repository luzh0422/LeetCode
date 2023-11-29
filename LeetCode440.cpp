//
// Created by 陆泽辉 on 2022/3/23.
//

#include "LeetCode440.h"

#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 利用优先队列的想法来实现，但是超时了。
 * @param n
 * @param k
 * @return
 */
int LeetCode440::findKthNumber(int n, int k) {
    unordered_map<int, vector<int>> uM;
    auto cmp = [&uM](int num1, int num2) -> bool {
        vector<int> nums1 = {};
        vector<int> nums2 = {};
        if (uM.count(num1)) {
            nums1 = uM[num1];
        } else {
            while (num1 != 0) {
                int temp = num1 % 10;
                nums1.push_back(temp);
                num1 /= 10;
            }
            uM.insert(unordered_map<int, vector<int>>::value_type (num1, nums1));
        }
        if (uM.count(num2)) {
            nums2 = uM[num2];
        } else {
            while (num2 != 0) {
                int temp = num2 % 10;
                nums2.push_back(temp);
                num2 /= 10;
            }
            uM.insert(unordered_map<int, vector<int>>::value_type (num2, nums2));
        }
        int index1 = nums1.size() - 1, index2 = nums2.size() - 1;
        while (index1 >= 0 && index2 >= 0) {
            if (nums1[index1] > nums2[index2]) {
                return true;
            } else if (nums1[index1] < nums2[index2]) {
                return false;
            } else {
                index1--;
                index2--;
            }
        }
        if (index1 < 0) {
            return false;
        } else {
            return true;
        }
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i = 1; i <= n; i++) {
        pq.push(i);
    }
    for (int i = 0; i < k - 1; i++) {
        pq.pop();
    }
    return pq.top();
}

