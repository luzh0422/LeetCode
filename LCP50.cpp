//
// Created by 陆泽辉 on 2023/9/15.
//

#include "LCP50.h"

int LCP50::giveGem(vector<int> &gem, vector<vector<int>> &operations) {
    for (auto& operation : operations) {
        int x = operation[0], y = operation[1];
        gem[y] += gem[x] / 2;
        gem[x] -= gem[x] / 2;
    }
    return *max_element(gem.begin(), gem.end()) - *min_element(gem.begin(), gem.end());
}
