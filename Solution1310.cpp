//
// Created by luzh on 2021/5/12.
//

#include "Solution1310.h"

vector<int> Solution1310::xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    int arrSize = arr.size();
    vector<int> preOrderXOR(arrSize);
    preOrderXOR[0] = arr[0];
    for (int i = 1; i < arrSize; i++) {
        preOrderXOR[i] = preOrderXOR[i - 1] ^ arr[i];
    }
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++) {
        int left = queries[i][0];
        int right = queries[i][1];
        if (left == 0) {
            ans.push_back(preOrderXOR[right]);
        } else {
            int temp = preOrderXOR[left - 1] ^ preOrderXOR[right];
            ans.push_back(temp);
        }
    }
    return ans;
}
