//
// Created by luzh on 2021/8/19.
//

#include "Solution345.h"

#include <unordered_map>

string Solution345::reverseVowels(string s) {
    unordered_map<char, int> vowels;
    vowels['a'] = 1;
    vowels['A'] = 1;
    vowels['e'] = 1;
    vowels['E'] = 1;
    vowels['i'] = 1;
    vowels['I'] = 1;
    vowels['o'] = 1;
    vowels['O'] = 1;
    vowels['u'] = 1;
    vowels['U'] = 1;
    int start = 0, end = s.size() - 1;
    while (true) {
        while (start < end) {
           if (vowels.count(s[start])) {
               break;
           }
           start++;
        }
        while (start < end) {
            if (vowels.count(s[end])) {
                break;
            }
            end--;
        }
        if (start >= end) {
            break;
        }
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
    return s;
}
