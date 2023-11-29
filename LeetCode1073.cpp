//
// Created by 陆泽辉 on 2023/5/18.
//

#include "LeetCode1073.h"

vector<int> LeetCode1073::addNegabinary(vector<int> &arr1, vector<int> &arr2) {
    int i = arr1.size() - 1, j = arr2.size() - 1;
    int carry = 0;
    vector<int> ans;
    while (i >= 0 || j >= 0 || carry) {
        int x = carry;
        if (i >= 0)
            x += arr1[i];
        if (j >= 0)
            x += arr2[j];
        if (x >= 2) {
            // 因为是-2进制,所以要进位-1；
            ans.push_back(x - 2);
            carry = -1;
        } else if (x >= 0) {
            ans.push_back(x);
            carry = 0;
        } else {
            // -(-2) ^ i = (-2) ^ (i + 1) + (-2) ^ i;
            // 进制数不能填写 -1，所以要将-1，转化为11；
            ans.push_back(1);
            carry = 1;
        }
        --i;
        --j;
    }
    while (ans.size() > 1 && ans.back() == 0) {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
