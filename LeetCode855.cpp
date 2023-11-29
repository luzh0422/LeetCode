//
// Created by 陆泽辉 on 2022/12/30.
//

#include "LeetCode855.h"


ExamRoom::ExamRoom(int n) {
    _n = n;
}

int ExamRoom::seat() {
    if (_seated.empty()) {
        _seated.insert(0);
        return 0;
    }
    if (_seated.size() == 1) {
        int position1 = *_seated.begin();
        if (position1 - 0 > _n - 1 - position1) {
            _seated.insert(0);
            return 0;
        } else {
            _seated.insert(_n - 1);
            return _n - 1;
        }
    }
    int distance = 0;
    int position1 = *_seated.begin();
    distance = position1 - 0;
    int curr = 0;
    auto iter = _seated.begin();
    advance(iter, 1);
    while (iter != _seated.end()) {
        int position2 = *iter;
        int temp = (position1 + position2) / 2;
        int currDistance = min(temp - position1, position2 - temp);
        if (currDistance > distance) {
            curr = temp;
            distance = currDistance;
        }
        position1 = position2;
    }
    position1 = *_seated.rbegin();
    int currDistance = (_n - 1 - position1);
    if (currDistance > distance) {
        distance = currDistance;
        curr = _n - 1;
    }
    _seated.insert(curr);
    return curr;
}

void ExamRoom::leave(int p) {
    if (_seated.count(p)) {
        _seated.erase(p);
    }
}
