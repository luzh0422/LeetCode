//
// Created by luzh on 2021/12/10.
//

#include "Solution748.h"

string Solution748::shortestCompletingWord(string licensePlate, vector<string> &words) {
    int currLength = INT_MAX;
    vector<int> licenseArr = getCharNums(licensePlate);
    string ans = "";
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        int n = word.size();
        if (n < currLength) {
            vector<int> wordArr = getCharNums(word);
            if (judgeArr(licenseArr, wordArr)) {
                currLength = n;
                ans = word;
            }
        }
    }
    return ans;
}

vector<int> Solution748::getCharNums(string &word) {
    vector<int> ans(26, 0);
    for (int i = 0; i < word.size(); i++) {
        char c = word[i];
        if (c >= 'a' && c <= 'z') {
            ans[c - 'a']++;
        } else if (c >= 'A' && c <= 'Z') {
            ans[c - 'A']++;
        }
    }
    return ans;
}

bool Solution748::judgeArr(vector<int> &arr1, vector<int> &arr2) {
    for (int i = 0; i < 26; i++) {
        if (arr1[i] > arr2[i]) {
            return false;
        }
    }
    return true;
}
