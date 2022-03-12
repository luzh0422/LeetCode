//
// Created by luzh on 2021/7/29.
//

#include "Solution1104.h"
#include <algorithm>
#include "math.h"

vector<int> Solution1104::pathInZigZagTree(int label) {
    vector<int> tree;
    int level = 0;
    int curr = 0;
    while (curr < label) {
        if (level % 2 == 0) {
            int temp = pow(2, level);
            for (int i = 0; i < temp; i++) {
                tree.push_back(i + temp);
                curr = i + temp;
                if (i + temp == label) {
                    break;
                }
            }
        } else {
            int temp = pow(2, level);
            for (int i = temp - 1; i >= 0; i--) {
                tree.push_back(i + temp);
                curr = i + temp;
                if (i + temp == label) {
                    break;
                }
            }
        }
        level++;
    }
    int node = tree.size() - 1;
    vector<int> ans;
    while (node >= 0) {
        ans.insert(ans.begin(), tree[node]);
        if (node - 1 < 0) {
            break;
        }
        node = (node - 1) / 2;
    }
    return ans;
}
