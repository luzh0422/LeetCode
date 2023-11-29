//
// Created by 陆泽辉 on 2023/5/6.
//

#include "LeetCode1419.h"

int LeetCode1419::minNumberOfFrogs(string croakOfFrogs) {
    int cCount = 0;
    int rCount = 0;
    int oCount = 0;
    int aCount = 0;
    int kCount = 0;
    int res = 0;
    int n = croakOfFrogs.size();
    for (int i = 0; i < n; i++) {
        switch (croakOfFrogs[i]) {
            case 'c':
                cCount++;
                break;
            case 'r':
                if (cCount > rCount) {
                    rCount++;
                } else {
                    return -1;
                }
                break;
            case 'o':
                if (rCount > oCount) {
                    oCount++;
                } else {
                    return -1;
                }
                break;
            case 'a':
                if (oCount > aCount) {
                    aCount++;
                } else {
                    return -1;
                }
                break;
            case 'k':
                if (aCount > kCount) {
                    kCount++;
                } else {
                    return -1;
                }
                break;
        }
        res = max({res, cCount, rCount, oCount, aCount, kCount});
        if (cCount > 0 && rCount > 0 && oCount > 0 && aCount > 0 && kCount > 0) {
            cCount--;
            rCount--;
            oCount--;
            aCount--;
            kCount--;
        }
    }
    if (cCount > 0 || rCount > 0 || oCount > 0 || aCount > 0 || kCount > 0) {
        return -1;
    }
    return res;
}
