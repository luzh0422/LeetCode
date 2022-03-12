//
// Created by luzh on 2021/10/14.
//

#include "SolutionOffer069.h"

int SolutionOffer069::peakIndexInMountainArray(vector<int> &arr) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int middle = (left + right) / 2;
        if (middle == 0) {
            left = middle + 1;
        } else if (arr[middle - 1] < arr[middle] && arr[middle] > arr[middle + 1]) {
            return middle;
        } else if (arr[middle - 1] < arr[middle] && arr[middle] < arr[middle + 1]) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return left;
}
