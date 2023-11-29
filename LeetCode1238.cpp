//
// Created by 陆泽辉 on 2023/2/23.
//

#include "LeetCode1238.h"
#include <numeric>

vector<int> LeetCode1238::circularPermutation(int n, int start) {
    vector<string> grayCode = GrayCode(n);
    vector<int> grayCodeNumber = parse2To10(grayCode);
    int i = 0;
    for (; i < grayCodeNumber.size(); i++) {
        if (grayCodeNumber[i] == start) {
            break;
        }
    }
    vector<int> res = {};
    for (int j = i; j < grayCodeNumber.size(); j++) {
        res.push_back(grayCodeNumber[j]);
    }
    for (int j = 0; j < i; j++) {
        res.push_back(grayCodeNumber[j]);
    }
    return res;
}

vector<string> LeetCode1238::GrayCode(int n) {
    if (n == 1) {
        return {"0", "1"};
    }
    int count = pow(2, n);
    vector<string> res(count, "");
    vector<string> last = GrayCode(n - 1);
    for (int i = 0; i < last.size(); i++) {
        res[i] = "0" + last[i];
        res[count - 1 - i] = "1" + last[i];
    }
    return res;
}

vector<int> LeetCode1238::parse2To10(vector<string>& binarys) {
    int n = binarys.size();
    vector<int> res;
    for (int i = 0; i < n; i++) {
        string binary = binarys[i];
        int temp = 0;
        for (int i = 0; i< binary.size(); i++) {
            temp += (binary[i] - '0') * pow(2, binary.size() - i - 1);
        }
        res.push_back(temp);
    }
    return res;
}
