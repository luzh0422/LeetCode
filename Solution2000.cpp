//
// Created by luzh on 2022/2/2.
//

#include "Solution2000.h"

string Solution2000::reversePrefix(string word, char ch) {
    int index = -1;
    int n = word.size();
    for (int i = 0; i < n; i++) {
        if (word[i] == ch) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        return word;
    } else {
        int start = 0;
        int end = index;
        while (start < end) {
            char temp = word[start];
            word[start] = word[end];
            word[end] = temp;
            start++;
            end--;
        }
    }
    return word;
}
