//
// Created by 陆泽辉 on 2022/11/3.
//

#include "LeetCode1668.h"

int LeetCode1668::maxRepeating(string sequence, string word) {
    int index = 1;
    string delta = word;
    while (delta.size() < sequence.size() && sequence.find(delta) != -1) {
        index++;
        delta += word;
    }
    return --index;
}
