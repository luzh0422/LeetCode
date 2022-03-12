//
// Created by luzh on 2021/3/25.
//

#include "Solution42.h"
#include <map>

ListNode * Solution42::deleteDuplicates(ListNode *head) {
    std::map<int, int> m;
    ListNode* node = head;
    while (node != NULL) {
        if (m.find(node->val) != m.end()) {
            m[node->val]++;
        } else {
            m.insert(std::map<int, int>::value_type(node->val, 1));
        }
        node = node->next;
    }
    ListNode* ans = new ListNode();
    node = ans;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (it->second == 1) {
            ListNode* node1 = new ListNode(it->first);
            node->next = node1;
            node = node->next;
        }
    }
    return ans;
}
