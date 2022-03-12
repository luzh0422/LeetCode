//
// Created by luzh on 2021/9/24.
//

#include "Solution430.h"

Node * Solution430::flatten(Node *head) {
    Node* node = head;
    while (node != nullptr) {
        if (node->child != nullptr) {
            Node* temp = node->next;
            Node* nextNode = flatten(node->child);
            nextNode->prev = node;
            node->next = nextNode;
            while (node->next != nullptr) {
                node->child = nullptr;
                node = node->next;
            }
            if (temp != nullptr) {
                temp->prev = node;
                node->next = temp;
            }
        }
        node->child = nullptr;
        node = node->next;
    }
    return head;
}
