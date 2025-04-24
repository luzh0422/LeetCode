//
// Created by luzehui on 25-3-13.
//

#include "LeetCode3306.h"
#include <unordered_set>
#include <unordered_map>

long long LeetCode3306::countOfSubstrings(std::string word, int k) {
    return countOfSubstringsHelp(word, k + 1) - countOfSubstringsHelp(word, k);
}

long long LeetCode3306::countOfSubstringsHelp(std::string &word, int k) {
    int res = 0;
    unordered_set<char> c = {'a', 'e', 'i', 'o', 'u'};
    unordered_map<char, int> cache = {};
    int i = 0, j = 0, n = word.size(), consonants = 0;
    while (i < n) {
        while (j < n && (consonants < k || cache.size() < 5)) {
            if (c.count(word[j])) {
                cache[word[j]]++;
            } else {
                consonants++;
            }
            j++;
        }
        if (consonants >= k && cache.size() == 5) {
            res += n - j + 1;
        }
        if (c.count(word[i])) {
            cache[word[i]]--;
            if (cache[word[i]] == 0) {
                cache.erase(word[i]);
            }
        } else {
            consonants--;
        }
        i++;
    }
    return res;
}
