//
// Created by luzh on 2021/7/22.
//

#include "Solution138.h"
#include <unordered_map>
#include <vector>

using namespace std;

Node * Solution138::copyRandomList(Node *head) {
    unordered_map<Node*, int> uM;
    vector<Node*> vec;
    Node* node = head;
    int index = 0;
    while (node != nullptr) {
        Node* temp = new Node(node->val);
        vec.push_back(temp);
        uM[node] = index;
        index++;
        node = node->next;
    }
    node = head;
    index = 0;
    while (node != nullptr) {
        if (index < vec.size() - 1) {
            vec[index]->next = vec[index + 1];
        } else {
            vec[index]->next = nullptr;
        }
        if (uM.count(node->random)) {
            vec[index]->random = vec[uM[node->random]];
        } else {
            vec[index]->random = nullptr;
        }
        index++;
        node = node->next;
    }
    return vec.empty() ? nullptr : vec.front();
}
