//
// Created by luzh on 2021/7/21.
//

#include "SolutionOffer52.h"

ListNode * SolutionOffer52::getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lengthA = 0, lengthB = 0;
    ListNode* nodeA = headA;
    ListNode* nodeB = headB;
    while (nodeA != nullptr) {
        lengthA++;
        nodeA = nodeA->next;
    }
    while (nodeB != nullptr) {
        lengthB++;
        nodeB = nodeB->next;
    }
    nodeA = headA;
    nodeB = headB;
    if (lengthA > lengthB) {
        int delta = lengthA - lengthB;
        while (delta > 0 && nodeA != nullptr) {
            nodeA = nodeA->next;
            delta--;
        }

    } else {
        int delta = lengthB - lengthA;
        while (delta > 0 && nodeB != nullptr) {
            nodeB = nodeB->next;
            delta--;
        }
    }
    while (nodeA != nullptr && nodeB != nullptr) {
        if (nodeA == nodeB) {
            return nodeA;
        }
        nodeA = nodeA->next;
        nodeB = nodeB->next;
    }
    return nullptr;
}
