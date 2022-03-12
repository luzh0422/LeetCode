//
// Created by luzh on 2021/4/21.
//

#include "Solution91.h"

#include <vector>

int Solution91::numDecodings(string s) {
    int size = s.size();
    vector<int> dp(size);
    /**
     * initialize;
     */
    for (int i = 0; i < 2 && i < size; i++) {
        if (i == 0) {
            if (s[i] == '0') {
                /**
                 * 此时无法编码；
                 */
                return 0;
            } else {
                dp[i] = 1;
            }
        } else if (i == 1) {
            if (s[i - 1] == '1') {
                if (s[i] == '0') {
                    dp[i] = 1;
                } else {
                    dp[i] = 2;
                }
            } else if (s[i - 1] == '2') {
                if (s[i] > '6' || s[i] == '0') {
                    dp[i] = 1;
                } else {
                    dp[i] = 2;
                }
            } else {
                /**
                 * 此时无法进行编码；
                 */
                if (s[i] == '0') {
                    return 0;
                } else {
                    dp[i] = dp[i - 1];
                }
            }
        }
    }

    for (int i = 2; i < size; i++) {
        if (s[i - 1] == '0' && s[i] == '0') {
            /**
             * 此时无法解码；
             */
            return 0;
        } else if (s[i - 1] == '1') {
            if (s[i] == '0') {
                dp[i] = dp[i - 2];
            } else {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        } else if (s[i - 1] == '2') {
            if (s[i] > '6') {
                dp[i] = dp[i - 1];
            } else if (s[i] == '0') {
                dp[i] = dp[i - 2];
            } else {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        } else {
            if (s[i] == '0') {
                /**
                 * 此时无法编码；
                 */
                return 0;
            } else {
                dp[i] = dp[i - 1];
            }
        }
    }
    return dp[size - 1];
}

