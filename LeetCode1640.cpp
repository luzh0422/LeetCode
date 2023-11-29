//
// Created by 陆泽辉 on 2022/9/22.
//

#include "LeetCode1640.h"
#include <unordered_map>

bool LeetCode1640::canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
    unordered_map<int, int> piecePosition = {};
    int piecesN = pieces.size();
    for (int i = 0; i < piecesN; i++) {
        piecePosition.insert(unordered_map<int, int>::value_type (pieces[i][0], i));
    }
    int arrN = arr.size();
    for (int i = 0; i < arrN; ) {
        if (piecePosition.count(arr[i])) {
            auto& piece = pieces[piecePosition[arr[i]]];
            int m = piece.size();
            int j = 0;
            while (i < arrN && j < m && piece[j] == arr[i]) {
                i++;
                j++;
            }
            if (j < m) {
                return false;
            }
        } else {
            return false;
        }
    }
    return true;
}
