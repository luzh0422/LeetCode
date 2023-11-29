//
// Created by 陆泽辉 on 2023/1/1.
//

#include "LeetCode2351.h"

#include <vector>

char LeetCode2351::repeatedCharacter(std::string s) {
    vector<int> arr(26, 0);
    for (auto c : s) {
        if (arr[c - 'a'] == 1) {
            return c;
        }
        arr[c - 'a'] = 1;
    }
    return 'a';
}

