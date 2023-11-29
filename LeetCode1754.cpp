//
// Created by 陆泽辉 on 2022/12/24.
//

#include "LeetCode1754.h"

string LeetCode1754::largestMerge(string word1, string word2) {
    int index1 = 0, index2 = 0;
    string ans = "";
    while(word1[index1] != '\0' && word2[index2] != '\0') {
        int k = 0;
        while(word1[index1+k] != '\0' && word2[index2+k] != '\0' && word1[index1+k] == word2[index2+k])
            k++;
        if(word1[index1+k] < word2[index2+k]) {
            ans += word2[index2++];
        } else {
            ans += word1[index1++];
        }
    }
    if (index1 < word1.size()) {
        ans += word1.substr(index1, word1.size());
    }
    if (index2 < word2.size()) {
        ans += word2.substr(index2, word2.size());
    }
    return ans;
}
