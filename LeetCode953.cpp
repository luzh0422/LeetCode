//
// Created by 陆泽辉 on 2022/5/17.
//

#include "LeetCode953.h"
#include <unordered_map>

bool LeetCode953::isAlienSorted(vector<string> &words, string order) {
    unordered_map<char, int> orderBook;
    for (int i = 0; i < 26; i++) {
        orderBook.insert(unordered_map<char, int>::value_type (order[i], i));
    }
    int n = words.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string word1 = words[i];
            string word2 = words[j];
            int n1 = word1.size(), n2 = word2.size();
            int index = 0;
            while (index < n1 && index < n2) {
                if (orderBook[word1[index]] > orderBook[word2[index]]) {
                    return false;
                } else if (orderBook[word1[index]] < orderBook[word2[index]]){
                    break;
                }
                index++;
            }
            if (index < n1 && index == n2) {
                return false;
            }
        }
    }
    return true;
}
