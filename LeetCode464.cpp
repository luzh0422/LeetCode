//
// Created by 陆泽辉 on 2022/5/22.
//

#include "LeetCode464.h"
#include <unordered_map>


bool LeetCode464::canIWin(int maxChoosableInteger, int desiredTotal) {
    if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
        return false;
    unordered_map<int, bool> records;
    return canIWin(maxChoosableInteger, desiredTotal, 0, records);
}

bool LeetCode464::canIWin(int maxChoosableInteger, int desiredTotal, int used, unordered_map<int, bool> &records) {
    if (records.count(used)) {
        return records[used];
    }
    for (int i = 0; i < maxChoosableInteger; i++) {
        int curr = 1 << i;
        if ((curr & used) == 0) {
            if (desiredTotal <= i + 1 || !canIWin(maxChoosableInteger, desiredTotal - i - 1, used | curr, records)) {
                records.emplace(used, true);
                return true;
            }
        }
    }
    records.emplace(used, false);
    return false;
}
