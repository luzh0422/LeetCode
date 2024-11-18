//
// Created by luzehui on 2024/5/20.
//

#include "LeetCode826.h"

int LeetCode826::maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
    vector<pair<int, int>> difficultyAndProfit;
    int n = difficulty.size(), res = 0, m = worker.size(), j = 0, best = 0;
    for (int i = 0; i < n; i++) {
        difficultyAndProfit.emplace_back(difficulty[i], profit[i]);
    }
    std::sort(difficultyAndProfit.begin(), difficultyAndProfit.end(), [](const pair<int, int>& difficultyAndProfit1, const pair<int, int>& difficultyAndProfit2) -> bool {
        if (difficultyAndProfit1.first < difficultyAndProfit2.first) {
            return true;
        } else if (difficultyAndProfit1.first == difficultyAndProfit2.first) {
            return difficultyAndProfit1.second >= difficultyAndProfit2.second;
        }
        return false;
    });
    std::sort(worker.begin(), worker.end());
    for (int i = 0; i < m; i++) {
        int w = worker[i];
        while (j < n && w >= difficultyAndProfit[j].first) {
            best = max(best, difficultyAndProfit[j].second);
        }
        res += best;
    }
    return res;
//    auto binarySearch = [&](int currWorker) -> int {
//        int left = 0, right = n - 1, maxProfit = 0, index = -1;
//        while (left <= right) {
//            int middle = (left + right) / 2;
//            auto dp = difficultyAndProfit[middle];
//            int currDiff = dp.first;
//            int currProfit = dp.second;
//            if (currDiff > currWorker) {
//                right = middle - 1;
//            } else {
//                left = middle + 1;
//            }
//            if (currDiff <= currWorker && currProfit > maxProfit) {
//                maxProfit = currProfit;
//            }
//        }
//        return maxProfit;
//    };
}
