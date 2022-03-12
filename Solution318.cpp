//
// Created by luzh on 2021/11/17.
//

#include "Solution318.h"

int Solution318::maxProduct(vector<string> &words) {
    int n = words.size();
    if (n < 2) {
        return 0;
    }
    vector<int> wordsToInt(n, 0);
    string firstWord = words[0];
    int firstWordToInt = wordToInt(firstWord);
    wordsToInt[0] = firstWordToInt;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        string word = words[i];
        int curr = wordToInt(word);
        int currSize = word.size();
        for (int j = 0; j < i; j++) {
            if ((wordsToInt[j] & curr) == 0) {
                int temp = words[j].size();
                ans = max(ans, currSize * temp);
            }
        }
        wordsToInt[i] = curr;
    }
    return ans;
}

int Solution318::wordToInt(string &word) {
    int ans = 0;
    for (char &c : word) {
        ans |= 1 << (c - 'a');
    }
    return ans;
}
