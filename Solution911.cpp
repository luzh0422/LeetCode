//
// Created by luzh on 2021/12/11.
//

#include "Solution911.h"

TopVotedCandidate::TopVotedCandidate(vector<int> &persons, vector<int> &times) {
    int n = times.size();
    for (int i = 0; i < n; i++) {
        int person = persons[i];
        int time = times[i];
        auto record = records.find(time);
        if (record == records.end()) {
            records.insert(map<int, map<int, int>>::value_type(time, {}));
            int lastTimeWin = -1;
            if (records.size() > 1) {
                auto lastTime = --(--records.end());
                for (auto it = lastTime->second.begin(); it != lastTime->second.end(); it++) {
                    records[time][it->first] = it->second;
                }
                lastTimeWin = (--wins.end())->second;
            }
            if (records[time].count(person)) {
                records[time][person]++;
            } else {
                records[time][person] = 1;
            }
            if (lastTimeWin == -1 || person != lastTimeWin && records[time][person] >= records[time][lastTimeWin]) {
                wins[time] = person;
            } else {
                wins[time] = lastTimeWin;
            }
        } else {
            auto candidate = record->second;
            auto currWin = wins[time];
            if (candidate.count(person)) {
                candidate[person]++;
                if (person != currWin && candidate[person] >= candidate[currWin]) {
                    wins[time] = person;
                }
            } else {
                candidate[person] = 1;
                if (person != currWin && candidate[person] >= candidate[currWin]) {
                    wins[time] = person;
                }
            }
        }
    }
}

int TopVotedCandidate::q(int t) {
    auto it = wins.upper_bound(t);
    if (it == wins.begin()) {
        return -1;
    }
    return (--it)->second;
}
