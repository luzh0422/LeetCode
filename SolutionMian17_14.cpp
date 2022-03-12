//
// Created by luzh on 2021/9/3.
//

#include "SolutionMian17_14.h"

#include <queue>

vector<int> SolutionMian17_14::smallestK(vector<int> &arr, int k) {
//    vector<int> heap = {};
//    int size = arr.size();
//    for (int i = 0; i < size; i++) {
//        insert(heap, arr[i]);
//    }
//    vector<int> ans = {};
//    for (int i = 0; i < k && i < arr.size(); i++) {
//        ans.push_back(pop(heap));
//    }
    /**
     * 改用为优先队列实现；
     */
    vector<int> ans = {};
    priority_queue<int, vector<int>, greater<int>> pq = {};
    for (auto& num : arr) {
        pq.push(num);
    }
    for (int i = 0; i < k; i++) {
        if (!pq.empty()) {
            int num = pq.top();
            ans.push_back(num);
            pq.pop();
        }
    }
    return ans;
}

void SolutionMian17_14::insert(vector<int> &minHeap, int val) {
    minHeap.push_back(val);
    int curr = minHeap.size() - 1;
    while (curr >= 0) {
        int parent = (curr - 1) / 2;
        if (minHeap[parent] > minHeap[curr]) {
            int temp = minHeap[parent];
            minHeap[parent] = minHeap[curr];
            minHeap[curr] = temp;
            curr = parent;
        } else {
            break;
        }
    }
    return;
}

int SolutionMian17_14::pop(vector<int>& minHeap) {
    int top = minHeap[0];
    int size = minHeap.size();
    minHeap[0] = minHeap[--size];
    minHeap.resize(size);
    int curr = 0;
    while (curr < size) {
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        if (left < size && right < size) {
            if (minHeap[left] > minHeap[right]) {
                if (minHeap[curr] > minHeap[right]) {
                    int temp = minHeap[right];
                    minHeap[right] = minHeap[curr];
                    minHeap[curr] = temp;
                    curr = right;
                } else {
                    break;
                }
            } else {
                if (minHeap[curr] > minHeap[left]) {
                    int temp = minHeap[left];
                    minHeap[left] = minHeap[curr];
                    minHeap[curr] = temp;
                    curr = left;
                } else {
                    break;
                }
            }
        } else if (left < size) {
            if (minHeap[curr] > minHeap[left]) {
                int temp = minHeap[left];
                minHeap[left] = minHeap[curr];
                minHeap[curr] = temp;
                curr = left;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    return top;
}
