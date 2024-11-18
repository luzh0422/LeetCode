//
// Created by luzehui on 2024/9/28.
//

#include "LeetCode2024.h"

int LeetCode2024::maxConsecutiveAnswers(std::string answerKey, int k) {
    int res = 0, diff = 0, start = 0, n = answerKey.size();
    for (int i = 0; i < n; i++) {
        if (answerKey[i] == 'F') {
            diff++;
            while (start < n && diff > k) {
                if (answerKey[start] == 'F') {
                    diff--;
                }
                start++;
            }
            res = max(res, i - start + 1);
        }
    }
    diff = 0, start = 0;
    for (int i = 0; i < n; i++) {
        if (answerKey[i] == 'T') {
            diff++;
            while (start < n && diff > k) {
                if (answerKey[start] == 'T') {
                    diff--;
                }
                start++;
            }
            res = max(res, i - start + 1);
        }
    }
    return res;
}
