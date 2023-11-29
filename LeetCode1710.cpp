//
// Created by 陆泽辉 on 2022/11/15.
//

#include "LeetCode1710.h"

int LeetCode1710::maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    std::sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& boxType1, vector<int>& boxType2) -> bool {
        return boxType1[1] > boxType2[1];
    });
    int currSize = 0, ret = 0;
    for (int i = 0; i < boxTypes.size(); i++) {
        currSize += boxTypes[i][0];
        if (currSize >= truckSize) {
            ret += boxTypes[i][1] * (boxTypes[i][0] - (currSize - truckSize));
            break;
        } else {
            ret += boxTypes[i][1] * boxTypes[i][0];
        }
    }
    return ret;
}
