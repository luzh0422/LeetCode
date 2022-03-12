//
// Created by luzh on 2021/12/4.
//

#include "Solution383.h"
#include <vector>

bool Solution383::canConstruct(string ransomNote, string magazine) {
    vector<int> ransoms(26, 0);
    vector<int> magazines(26, 0);
    for (int i = 0; i < ransomNote.size(); i++) {
        ransoms[ransomNote[i] - 'a']++;
    }
    for (int i = 0; i < magazine.size(); i++) {
        magazines[magazine[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (ransoms[i] > magazines[i]) {
            return false;
        }
    }
    return true;
}
