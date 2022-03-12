//
// Created by luzh on 2021/12/19.
//

#include "Solution997.h"
#include <unordered_map>

int Solution997::findJudge(int n, vector<vector<int>> &trust) {
    vector<int> trusts(n, 0);
    vector<int> trusted(n, 0);
    int size = trust.size();
    for (int i = 0; i < size; i++) {
        auto& t = trust[i];
        int trustA = t[0];
        int trustB = t[1];
        trusts[trustA]++;
        trusted[trustB]++;
    }
    for (int i = 0; i < n; i++) {
        if (trusts[i] == 0 && trusted[i] == n - 1) {
            return i;
        }
    }
    return -1;
}
