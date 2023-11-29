//
// Created by 陆泽辉 on 2022/10/12.
//

#include "LeetCode817.h"
#include <unordered_set>

int LeetCode817::numComponents(ListNode *head, vector<int> &nums) {
    unordered_set<int> uS;
    for (auto num: nums) {
        uS.insert(num);
    }
    int ret = 0, curr = 0;
    ListNode* node = head;
    while (node != nullptr) {
        if (uS.count(node->val)) {
            if (curr == 0) {
                ret++;
            }
            curr++;
        } else {
            curr = 0;
        }
        node = node->next;
    }
    return ret;
}
