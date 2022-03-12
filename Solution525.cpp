//
// Created by luzh on 2021/6/3.
//

#include "Solution525.h"

#include <unordered_map>

int Solution525::findMaxLength(vector<int> &nums) {
    std::unordered_map<int, int> cache = {};
    /**
     * 当一个元素都没有的时候，counter计数为0，index记为-1（便于计算长度）；
     */
    cache.insert(unordered_map<int, int>::value_type(0, -1));
    int counter = 0;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            counter -= 1;
        } else {
            counter += 1;
        }
        if (cache.count(counter)) {
            ans = max(ans, i - cache[counter]);
        } else {
            cache.insert(unordered_map<int, int>::value_type(counter, i));
        }
    }
    return ans;
}
