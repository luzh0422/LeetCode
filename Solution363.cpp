//
// Created by luzh on 2021/4/22.
//

#include "Solution363.h"

#include <set>

int Solution363::maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int ans = INT_MIN;
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++) {
        vector<int> sum(n);
        for (int j = i; j < m; j++) {
            for (int k = 0; k < n; k++) {
                sum[k] += matrix[j][k];
            }
            set<int> sumSet{0};
            int s = 0;
            for (int v: sum) {
                s += v;
                auto lb = sumSet.lower_bound(s - k);
                if (lb != sumSet.end()) {
                    ans = max(ans, s - *lb);
                }
                sumSet.insert(s);
            }
        }
    }
    return ans;
}
