//
// Created by luzehui on 2024/5/11.
//

#include "LeetCode2391.h"

int LeetCode2391::garbageCollection(vector<std::string> &garbage, vector<int> &travel) {
    int currMIndex = 0, currPIndex = 0, currGIndex = 0;
    int n = garbage.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        string g = garbage[i];
        for (auto c : g) {
            if (c == 'M') {
                for (int j = currMIndex; j < i; j++) {
                    res += travel[j];
                }
                currMIndex = i;
                res++;
            } else if (c == 'P') {
                for (int j = currPIndex; j < i; j++) {
                    res += travel[j];
                }
                currPIndex = i;
                res++;
            } else if (c == 'G') {
                for (int j = currGIndex; j < i; j++) {
                    res += travel[j];
                }
                currGIndex = i;
                res++;
            }
        }
    }
    return res;
}
