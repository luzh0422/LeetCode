//
// Created by luzh on 2022/2/19.
//

#include "Solution969.h"

/**
 * 两次翻转可以将最大的数字移动到数组的末尾；
 * 首先找到最大数字的位置index，翻转0 - index，可以将最大的数字放在队首；
 * 然后翻转 0 - n，就可以将数字放在队尾；
 * 重复n次，即可将数组重新排序；
 * @param arr
 * @return
 */
vector<int> Solution969::pancakeSort(vector<int> &arr) {
    int n = arr.size();
    vector<int> ret;
    for (int i = n; i > 0; i--) {
        int index = max_element(arr.begin(), arr.begin() + i) - arr.begin();
        if (index == i - 1) {
            continue;
        }
        reverse(arr.begin(), arr.begin() + index + 1);
        reverse(arr.begin(), arr.begin() + i);
        ret.push_back(index + 1);
        ret.push_back(i);
    }
    return ret;
}
