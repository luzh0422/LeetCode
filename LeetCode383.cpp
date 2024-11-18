//
// Created by luzehui on 2024/1/7.
//

#include "LeetCode383.h"

#include <vector>

bool LeetCode383::canConstruct(std::string ransomNote, std::string magazine) {
    vector<int> ransonNoteArr(26, 0);
    vector<int> magazineArr(26, 0);
    for (auto& ch : ransomNote) {
        ransonNoteArr[ch - 'a']++;
    }
    for (auto& ch : magazine) {
        magazineArr[ch - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (ransonNoteArr[i] > magazineArr[i]) {
            return false;
        }
    }
    return true;
}
