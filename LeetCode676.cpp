//
// Created by 陆泽辉 on 2022/7/11.
//

#include "LeetCode676.h"

MagicDictionary::MagicDictionary() {

}

void MagicDictionary::buildDict(vector<string> dictionary) {
    mDictionary = dictionary;
}

bool MagicDictionary::search(string searchWord) {
    bool ret = false;
    for (string& dict: mDictionary) {
        if (dict.size() != searchWord.size()) {
            continue;
        }
        int n = dict.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dict[i] != searchWord[i]) {
                count++;
            }
        }
        if (count == 1) {
            ret = true;
            break;
        }
    }
    return ret;
}

