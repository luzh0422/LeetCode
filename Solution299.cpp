//
// Created by luzh on 2021/11/8.
//

#include "Solution299.h"
#include <vector>

using namespace std;

string Solution299::getHint(string secret, string guess) {
    int secretN = secret.size() - 1, guessN = guess.size() - 1;
    vector<int> secretNums(10, 0);
    vector<int> guessNums(10, 0);
    int ANum = 0;
    for (int i = secretN, j = guessN; i >= 0 && j >= 0; i--, j--) {
        if (secret[i] == guess[j]) {
            ANum++;
        }
        secretNums[secret[i] - '0'] ++;
        guessNums[guess[j] - '0'] ++;
    }
    int BNum = 0;
    for (int i = 0; i < 10; i++) {
        BNum += min(secretNums[i], guessNums[i]);
    }
    BNum -= ANum;
    return to_string(ANum) + "A" + to_string(BNum) + "B";
}
