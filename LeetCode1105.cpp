//
// Created by 陆泽辉 on 2023/4/23.
//

#include "LeetCode1105.h"
/**
  * 方法：动态规划
  *
  * 由于题目说 书要按照顺序排放，
  *
  * 那么题目可以翻译为：
  *
  * 将 books 划分为多个子数组，每个子数组中元素（书）的厚度之和不能超过 shelfWidth，返回 所有子数组中最大元素（书）的高度之和 的最小值
  *
  * 对某个数组本身求xxx的最值，通常定义 dp[i] 为 nums[0....i] 的最xxxxx
  *
  * 本题的目的是划分成多个子数组，这类问题，我们需要考虑的是子数组中到底要有几个元素，
  * 所以我们就可以枚举最后一个子数组中的元素个数，或者枚举最后一个子数组的起点 j，这样最后一个子数组为 nums[j...i]，长度为 i-j+1
  *
  * nums[j...i] 需要满足的条件时，元素（厚度）之和 不超过 shelfWidth
  *
  * 因此，定义 dp[i] 为 nums[0....i] 的所有划分方案中 得到的 所有子数组最大高度之和 的最小值
  *
  * 考虑 最后一个子数组是 nums[j...i]，j 是所有可能的起点，且 nums[j...i] 元素（厚度）之和 不超过 shelfWidth
  *
  * 那么接下来考虑 这个 j 是需要从 0 到 i 顺序枚举呢 ？ 还是 从 i 到 0 倒序枚举呢？
  *
  * 对于 dp[i]，nums[i] 已经确定是 最后一个元素，如果顺序枚举，没法快速知道 nums[j...i] 的厚度之和，也没法快速得到这部分书的最大高度
  *
  * 而如果 倒序枚举 j 从 i 到 0，用变量 w 记录 nums[i..j] 的元素厚度和，用 h 记录 nums[i..j] 的元素最大高度
  *
  * 这样，当 w > shelfWidth 就结束对 j 的枚举，说明放不下了，
  * 否则 ，h 就是 nums[i..j] 的最大高度，nums[0...j-1] 就是剩下的子问题，也就是 dp[j - 1]
  * 此时 dp[i] 就等于 dp[j - 1] + h
  * 在j的所有枚举过程中，取 dp[j - 1] + h 的最小值，就得到了 dp[i]
  *
  * 最后，返回 把nums[0...n-1]划分成多个部分得到的最大高度和的最小值，也就是 dp[n-1]
  *
  * 具体：
  *
  * 定义 int[] dp = new int[n];
  *
  * 由于 dp 求最小值，因此 初始化 dp[i] 为 inf
  *
  * 递推
  *
  * for (int i = 0; i < n; i++) {
  *     nums[i]是最后一个元素
  *     倒序枚举 j（最后一部分的其他元素）
  *     w = 0, h = 0，分别记录这部分元素的厚度和，最大高度
  *     for (int j = i; j >= 0; --j) {
  *              w += books[j][0];
  *              h = max(h, books[j][1])
  *              如果 w > shelfWidth;
  *                    break; 放不下了
  *              dp[i] = Math.min(dp[i], h + dp[j - 1]);  // 注意需要判断 j 不越界
  *     }
  * }
  *
  * 最后返回 dp[n-1]
  *
  * @param books
  * @param shelfWidth
  * @return
  */
int minHeightShelves(vector<vector<int>> books, int shelfWidth) {
    int n = books.size();
    // dp[i] 为 nums[0....i] 的所有划分方案中 得到的 所有子数组最大高度之和 的最小值
    // 由于 dp 求最小值，因此 初始化 dp[i] 为 inf
    vector<int> dp(n, 1000000);
    // 递推
    for (int i = 0; i < n; ++i) {
        //  nums[i]是最后一个元素
        //  倒序枚举 j（最后一部分的其他元素）
        //  w = 0, h = 0，分别记录这部分元素的厚度和，最大高度
        int w = 0, h = 0;
        for (int j = i; j >= 0; --j) {
            // 更新厚度和
            w += books[j][0];
            // 放不下了
            if (w > shelfWidth) {
                break;
            }
            // 更新 [j,i] 最大高度
            h = max(h, books[j][1]);
            // 更新 dp[i]，dp[j-1] 是子问题，注意越界
            dp[i] = min(dp[i], h + (j > 0 ? dp[j - 1] : 0));
        }
    }
    // 返回
    return dp[n - 1];
}
