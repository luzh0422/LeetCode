//
// Created by luzh on 2021/6/4.
//

#include "Solution160.h"

ListNode * Solution160::getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lengthA = 0, lengthB = 0;
    ListNode* nodeA = headA;
    ListNode* nodeB = headB;
    while (nodeA != nullptr) {
        lengthA += 1;
        nodeA = nodeA->next;
    }
    while (nodeB != nullptr) {
        lengthB += 1;
        nodeB = nodeB->next;
    }
    nodeA = headA;
    nodeB = headB;
    if (lengthA > lengthB) {
        int temp = lengthA - lengthB;
        while (temp > 0) {
            nodeA = nodeA->next;
            temp--;
        }
    } else {
        int temp = lengthB - lengthA;
        while (temp > 0) {
            nodeB = nodeB->next;
            temp--;
        }
    }
    while (nodeA != nullptr && nodeB != nullptr) {
        if (nodeA == nodeB) {
            return nodeA;
        } else {
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
    }
    return nullptr;
}
