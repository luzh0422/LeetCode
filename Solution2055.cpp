//
// Created by luzh on 2022/3/8.
//

#include "Solution2055.h"

vector<int> Solution2055::platesBetweenCandles(string s, vector<vector<int>> &queries) {
    int n = s.size();
    vector<int> preSums(n);
    int preSum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            preSum++;
        }
        preSums[i] = preSum;
    }
    vector<int> left(n);
    for (int i = 0, l = -1; i < n; i++) {
        if (s[i] == '|') {
            l = i;
        }
        left[i] = l;
    }
    vector<int> right(n);
    for (int i = n - 1, r = -1; i >= 0; i--) {
        if (s[i] == '|') {
            r = i;
        }
        right[i] = r;
    }
    int queriesN = queries.size();
    vector<int> ret(queriesN);
    for (int i = 0; i < queriesN; i++) {
        int leftCandle = right[queries[i][0]];
        int rightCandle = left[queries[i][1]];
        ret[i] = (leftCandle == -1 || rightCandle == -1 || leftCandle >= rightCandle) ? 0 : preSums[rightCandle] - preSums[leftCandle];
    }
    return ret;


//    vector<int> candlePositions;
//    int sN = s.size();
//    for (int i = 0; i < sN; i++) {
//        if (s[i] == '|') {
//            candlePositions.push_back(i);
//        }
//    }
//    vector<int> ret;
//    int queryN = queries.size();
//    for (int i = 0; i < queryN; i++) {
//        int left = queries[i][0];
//        int right = queries[i][1];
//        auto leftCandleIt = lower_bound(candlePositions.begin(), candlePositions.end(), left);
//        auto rightCandleIt = upper_bound(candlePositions.begin(), candlePositions.end(), right);
//        rightCandleIt--;
//        auto lastCandleIt = leftCandleIt;
//        leftCandleIt++;
//        int curr = 0;
//        while (leftCandleIt != candlePositions.end() && *leftCandleIt <= *rightCandleIt) {
//            curr += *leftCandleIt - *lastCandleIt - 1;
//            lastCandleIt = leftCandleIt;
//            leftCandleIt++;
//        }
//        ret.push_back(curr);
//    }
//    return ret;
}
