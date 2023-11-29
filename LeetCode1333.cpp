//
// Created by 陆泽辉 on 2023/9/27.
//

#include "LeetCode1333.h"

vector<int>
LeetCode1333::filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance) {
    vector<int> ids;
    int n = restaurants.size();
    for (int i = 0; i < n; i++) {
        auto restaurant = restaurants[i];
        if (veganFriendly == 0 || restaurant[2] == 1) {
            if (restaurant[3] <= maxPrice && restaurant[4] <= maxDistance) {
                ids.push_back(i);
            }
        }
    }
    std::sort(ids.begin(), ids.end(), [&](int id1, int id2) -> bool {
        if (restaurants[id1][1] > restaurants[id2][1]) {
            return true;
        } else if (restaurants[id1][1] == restaurants[id2][1] && restaurants[id1][0] > restaurants[id2][0]) {
            return true;
        }
        return false;
    });
    vector<int> res;
    for (int i = 0; i < ids.size(); i++) {
        res.push_back(restaurants[ids[i]][0]);
    }
    return res;
}
