//
// Created by 陆泽辉 on 2023/2/20.
//

#include "LeetCode2347.h"
#include <unordered_map>

string LeetCode2347::bestHand(vector<int> &ranks, vector<char> &suits) {
    bool tag = true;
    for (int i = 1; i < 5; i++) {
        if (suits[i] != suits[i - 1]) {
            tag = false;
        }
    }
    if (tag) {
        return "Flush";
    }
    tag = true;
    unordered_map<int, int> uM;
    for (int i = 0; i < 5; i++) {
        int rank = ranks[i];
        if (uM.count(ranks[i])) {
            uM[rank]++;
        } else {
            uM.insert(unordered_map<int, int>::value_type (rank, 1));
        }
        if (uM[rank] == 3) {
            return "Three of a Kind";
        } else if (uM[rank] == 2) {
            tag = false;
        }
    }
    if (!tag) {
        return "Pair";
    }
    return "High Card";
}
