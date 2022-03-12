//
// Created by luzh on 2021/10/26.
//

#include "Solution496.h"
#include <unordered_map>

vector<int> Solution496::nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> uM;
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> ans = {};
    for (int i = 0; i < n2; i++) {
        uM[nums2[i]] = i;
    }
    for (int i = 0; i < n1; i++) {
        int start = uM[nums1[i]];
        bool tag = false;
        for (int j = start; j < n2; j++) {
            if (nums2[j] > nums1[i]) {
                ans.push_back(nums2[j]);
                tag = true;
                break;
            }
        }
        if (!tag) {
            ans.push_back(-1);
        }
    }
    return ans;
}
