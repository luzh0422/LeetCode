//
// Created by 陆泽辉 on 2022/10/20.
//

#include "LeetCode779.h"
#include <iostream>
#include <string>

using namespace std;

int LeetCode779::kthGrammar(int n, int k) {
    if (k == 1) {
        return 0;
    }
    if (k > (1 << (n - 2))) {
        return 1 ^ kthGrammar(n - 1, k - (1 << (n - 2)));
    }
    return kthGrammar(n - 1, k);
}
