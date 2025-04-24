//
// Created by luzehui on 25-2-24.
//

#include "LeetCode1656.h"

OrderedStream::OrderedStream(int n) {
    values.resize(n, "");
}

vector<string> OrderedStream::insert(int idKey, std::string value) {
    values[idKey] = value;
    vector<string> res{};
    if (ptr == idKey) {
        while (ptr < values.size() && values[ptr] != "") {
            res.push_back(values[ptr++]);
        }
    }
    return res;
}
