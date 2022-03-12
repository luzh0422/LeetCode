//
// Created by luzh on 2021/5/11.
//

#include "Solution1734.h"

vector<int> Solution1734::decode(vector<int> &encoded) {
    int n = encoded.size() + 1;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        total ^= i;
    }
    int encode = 0;
    for (int i = 1; i < encoded.size(); i += 2) {
        encode ^= encoded[i];
    }
    int first = total ^ encode;
    vector<int> ans(n);
    ans[0] = first;
    for (int i = 1; i < n; i++) {
        ans[i] = ans[i - 1] ^ encoded[i - 1];
    }
    return ans;
}
