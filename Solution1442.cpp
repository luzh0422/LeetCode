//
// Created by luzh on 2021/5/18.
//

#include "Solution1442.h"

#include <map>

int Solution1442::countTriplets(vector<int> &arr) {
    int size = arr.size();
    vector<int> preXOR(size + 1);
    for (int i = 0; i < size; i++) {
        preXOR[i + 1] = preXOR[i] ^ arr[i];
    }
    int ans = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (preXOR[i] == preXOR[j + 1]) {
                ans += (j - i);
            }
        }
    }
    return ans;
}
