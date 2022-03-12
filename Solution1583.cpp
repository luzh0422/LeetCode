//
// Created by luzh on 2021/8/14.
//

#include "Solution1583.h"
#include <unordered_map>

int Solution1583::unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs) {
    unordered_map<int, int> uM;
    vector<unordered_map<int, int>> vUm(n);
    for (int i = 0; i < n; i++) {
        auto preference = preferences[i];
        for (int j = 0; j < n - 1; j++) {
            vUm[i][preference[j]] = j;
        }
    }
    for (int i = 0; i < pairs.size(); i++) {
        auto pair = pairs[i];
        int first = pair[0];
        int second = pair[1];
        uM[first] = second;
        uM[second] = first;
    }
    int ans = 0;
    for (auto it = uM.begin(); it != uM.end(); it++) {
        int curr = it->first;
        int pair = it->second;
        auto preference = preferences[curr];
        for (int i = 0; i < n; i++) {
            if (preference[i] == pair) {
                break;
            }
            int higherPair = preference[i];
            if (uM.count(higherPair)) {
                int higherPairPair = uM[higherPair];
                int higherPairPairIndex = vUm[higherPair][higherPairPair];
                int currIndex = vUm[higherPair][curr];
                if (currIndex < higherPairPairIndex) {
                    ans += 1;
                    break;
                }
            }
        }
    }
    return ans;
}
