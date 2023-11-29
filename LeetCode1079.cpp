//
// Created by 陆泽辉 on 2023/5/19.
//

#include "LeetCode1079.h"

/**
 * 回溯算法：有条件的深度优先遍历；
 * 本题的条件就是，用光了所有的字符；
 */
int LeetCode1079::numTilePossibilities(string tiles) {
    unordered_map<char, int> count;
    /**
     * 通过set可以遍历所有的字符，然后根据字符使用的数量进行回溯；
     */
    set<char> tile;
    for (char c : tiles) {
        count[c]++;
        tile.insert(c);
    }
    return dfs(count, tile) - 1;
}

int LeetCode1079::dfs(unordered_map<char, int> &count, set<char> &tile) {
    int res = 1;
    /**
     * 每个字符作为首字母；
     */
    for (char t : tile) {
        if (count[t] > 0) {
            /**
             * 用了一个字符，则这个字符的数量要-1；
             */
            count[t]--;
            res += dfs(count, tile);
            count[t]++;
        }
    }
    return res;
}
