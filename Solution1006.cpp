//
// Created by luzh on 2021/4/1.
//

#include "Solution1006.h"
#include <queue>

using namespace std;

int Solution1006::clumsy(int N) {
    queue<int> q;
    int step = 0;
    int ans = 1;
    while (N > 0) {
        switch (step) {
            case 0:
                ans = N;
                N--;
                break;
            case 1:
                ans *= N;
                N--;
                break;
            case 2:
                ans /= N;
                N--;
                break;
            case 3:
                q.push(ans);
                ans = 0;
                q.push(N);
                N--;
                break;
        }
        step++;
        step %= 4;
    }
    q.push(ans);
    int res = q.front();
    step = 0;
    q.pop();
    while (!q.empty()) {
        if (step == 0) {
            res += q.front();
        } else {
            res -= q.front();
        }
        step ^= 1;
        q.pop();
    }
    return res;
}
