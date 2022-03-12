//
// Created by luzh on 2021/5/6.
//

#include "Solution1720.h"

vector<int> Solution1720::decode(vector<int> &encoded, int first) {
    vector<int> res = {};
    res.push_back(first);
    for (int i = 0; i < encoded.size(); i++) {
        int temp = encoded[i] ^ res[i];
        res.push_back(temp);
    }
    return res;
}
