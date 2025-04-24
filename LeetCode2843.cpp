//
// Created by luzehui on 25-4-11.
//

#include "LeetCode2843.h"
#include <vector>

using namespace std;

int LeetCode2843::countSymmetricIntegers(int low, int high) {
    vector<int> M(5, 0);
    auto check = [&](int num) -> bool {
        int x = 0;
        while (num != 0) {
            M[x] = num % 10;
            num /= 10;
            x++;
        }
        if ((x & 1) == 1) {
            return false;
        }
        int res = 0;
        for (int i = 0; i < x / 2; i++) {
           res += M[i];
        }
        for (int i = x / 2; i < x; i++) {
            res -= M[i];
        }
        return res == 0;
    };
    int res = 0;
    while (low <= high) {
        if (check(low)) {
            res++;
        }
        low++;
    }
    return res;
}
