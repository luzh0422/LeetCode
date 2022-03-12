//
// Created by luzh on 2021/9/22.
//

#include "Solution725.h"

vector<ListNode *> Solution725::splitListToParts(ListNode *head, int k) {
    int headLength = 0;
    ListNode* node = head;
    while (node != nullptr) {
        node = node->next;
        headLength++;
    }
    vector<ListNode*> ans = {};
    node = head;
    if (headLength <= k) {
        while (node != nullptr) {
            ListNode* temp = node->next;
            node->next = nullptr;
            ans.push_back(node);
            node = temp;
        }
        for (int i = 0; i < k - headLength; i++) {
            ans.push_back(nullptr);
        }
    } else {
        int step = headLength / k;
        int delta = headLength % k;
        int index = 0;
        while (node != nullptr) {
            if (delta > 0 && index == step || delta == 0 && index == step - 1) {
                ListNode* temp = node->next;
                node->next = nullptr;
                node = temp;
                index = 0;
                if (delta > 0) delta--;
            } else {
                if (index == 0) ans.push_back(node);
                node = node->next;
                index++;
            }
        }
    }
    return ans;
}
