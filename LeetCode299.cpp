//
// Created by luzehui on 2024/3/10.
//

#include "LeetCode299.h"

string LeetCode299::getHint(std::string secret, std::string guess) {
    vector<int> hints1(10, 0);
    vector<int> hints2(10, 0);
    int A = 0, B = 0;
    int n = secret.size();
    for (int i = 0; i < n; i++) {
        if (secret[i] == guess[i]) {
            A++;
        } else {
            hints1[secret[i] - '0']++;
            hints2[guess[i] - '0']++;
        }
    }
    for (int i = 0; i < 10; i++) {
        B += min(hints1[i], hints2[i]);
    }
    return to_string(A) + "A" + to_string(B) + "B";
}
