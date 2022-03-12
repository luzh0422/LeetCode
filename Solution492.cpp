//
// Created by luzh on 2021/10/23.
//

#include "Solution492.h"
#include "algorithm"
#include "math.h"

vector<int> Solution492::constructRectangle(int area) {
    int temp = sqrt(area);
    vector<int> ans = {};
    for (int i = temp; i > 0; i--) {
        if (area % i == 0) {
            if (i > area / i) {
                ans.push_back(i);
                ans.push_back(area / i);
            } else {
                ans.push_back(area / i);
                ans.push_back(i);
            }
            break;
        }
    }
    return ans;
}
