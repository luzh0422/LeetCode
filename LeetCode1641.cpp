//
// Created by 陆泽辉 on 2023/3/29.
//

#include "LeetCode1641.h"

using namespace std;

int LeetCode1641::countVowelStrings(int n) {
    return countVowelStrings(n, 'a') + countVowelStrings(n, 'e') + countVowelStrings(n, 'i') + countVowelStrings(n, 'o') + countVowelStrings(n, 'u');
}

int LeetCode1641::countVowelStrings(int n, char c) {
    if (n == 1) {
        return 1;
    }
    switch (c) {
        case 'u':
            return countVowelStrings(n - 1, 'a') + countVowelStrings(n - 1, 'e') + countVowelStrings(n - 1, 'i') + countVowelStrings(n - 1, 'o') + countVowelStrings(n - 1, 'u');
        case 'o':
            return countVowelStrings(n - 1, 'a') + countVowelStrings(n - 1, 'e') + countVowelStrings(n - 1, 'i') + countVowelStrings(n - 1, 'o');
        case 'i':
            return countVowelStrings(n - 1, 'a') + countVowelStrings(n - 1, 'e') + countVowelStrings(n - 1, 'i');
        case 'e':
            return countVowelStrings(n - 1, 'a') + countVowelStrings(n - 1, 'e');
        case 'a':
            return countVowelStrings(n - 1, 'a');
        default:
            return 0;
    }
}
