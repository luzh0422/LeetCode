//
// Created by luzh on 2022/3/17.
//

#include "LeetCode720.h"
#include <unordered_set>

string LeetCode720::longestWord(vector<string> &words) {
    std::sort(words.begin(), words.end(), [](string& word1, string& word2) -> bool {
        return word1.size() < word2.size();
    });
    int n = words.size();
    unordered_set<string> uS;
    string ret = "";
    for (int i = 0; i < n; i++) {
        string word = words[i];
        int wordSize = word.size();
        if (wordSize == 1) {
            uS.insert(word);
            if (wordSize > ret.size() || wordSize == ret.size() && word < ret) {
                ret = word;
            }
        } else {
            string temp = word.substr(0, wordSize - 1);
            if (uS.count(temp)) {
                uS.insert(word);
                if (wordSize > ret.size() || wordSize == ret.size() && word < ret) {
                    ret = word;
                }
            }
        }
    }
    return ret;
}
