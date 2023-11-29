//
// Created by 陆泽辉 on 2022/7/7.
//

#include "LeetCode648.h"

string LeetCode648::replaceWords(vector<string> &dictionary, string sentence) {
    string ret = "";
    std::sort(dictionary.begin(), dictionary.end(), [](string& s1, string& s2) -> bool {
        return s1.size() < s2.size();
    });
    auto isRootWord = [](string& rootWord, string& word) -> bool {
        int i = 0, j = 0;
        int n = rootWord.size(), m = word.size();
        if (n >= m) {
            return false;
        }
        for (; i < n && j < m; i++, j++) {
            if (rootWord[i] != word[j]) {
                break;
            }
        }
        if (i == n) {
            return true;
        } else {
            return false;
        }
    };
    int wordStart = 0, wordEnd = 0;
    int n = sentence.size(), m = dictionary.size();
    while (wordEnd < n) {
        if (sentence[wordEnd] == ' ') {
            string word = sentence.substr(wordStart, wordEnd - wordStart);
            bool tag = false;
            for (int i = 0; i < m; i++) {
                if (isRootWord(dictionary[i], word)) {
                    ret += dictionary[i];
                    tag = true;
                    break;
                }
            }
            if (!tag) {
                ret += word;
            }
            ret += " ";
            wordStart = wordEnd + 1;
            wordEnd = wordStart;
        } else {
            wordEnd++;
        }
    }
    if (wordStart != wordEnd) {
        string word = sentence.substr(wordStart, wordEnd - wordStart);
        bool tag = false;
        for (int i = 0; i < m; i++) {
            if (isRootWord(dictionary[i], word)) {
                ret += dictionary[i];
                tag = true;
                break;
            }
        }
        if (!tag) {
            ret += word;
        }
        wordStart = wordEnd + 1;
        wordEnd = wordStart;
    }
    return ret;
}
