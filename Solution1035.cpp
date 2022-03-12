//
// Created by luzh on 2021/5/21.
//

#include "Solution1035.h"

int Solution1035::maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
    vector<pair<int, int>> record = {};
    int ans = 0;
    for (int i = 0; i < nums1.size(); i++) {
        int num1 = nums1[i];
        for (int j = 0; j < nums2.size(); j++) {
            int num2 = nums2[j];
            if (num1 == num2) {
                record.emplace_back(i, j);
                int temp = 1;
                maxUncrossedLines(nums1, nums2, i + 1, j + 1, record, temp, ans);
                record.pop_back();
            }
        }
    }
    return ans;
}

void Solution1035::maxUncrossedLines(vector<int> &nums1, vector<int> &nums2, int nums1Start, int nums2Start,
                                    vector<pair<int, int>> &record, int& currAns, int& ans) {
    ans = max(ans, currAns);
    for (int i = nums1Start; i < nums1.size(); i++) {
        int num1 = nums1[i];
        for (int j = nums2Start; j < nums2.size(); j++) {
            int num2 = nums2[j];
            if (num1 == num2) {
                bool hasLine = false;
                for (int k = 0; k < record.size(); k++) {
                    if (record[k].second >= j) {
                        hasLine = true;
                        break;
                    }
                }
                if (!hasLine) {
                    record.emplace_back(i, j);
                    currAns += 1;
                    maxUncrossedLines(nums1, nums2, i, j, record, currAns, ans);
                    currAns -= 1;
                    record.pop_back();
                }
            }
        }
    }
}
