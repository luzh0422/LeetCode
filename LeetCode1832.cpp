//
// Created by 陆泽辉 on 2022/12/13.
//

#include "LeetCode1832.h"
#include <vector>

bool LeetCode1832::checkIfPangram(string sentence) {
    vector<int> chars(26, 0);
    int count = 0;
    for (auto& c : sentence) {
        if (chars[c - 'a'] == 0) {
            chars[c - 'a'] = 1;
            count++;
        }
    }
    return count == 26;
}
