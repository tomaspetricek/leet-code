//
// Created by Tomáš Petříček on 26.06.2023.
//

#ifndef LEET_CODE_SNAPSHOT_ARRAY_HPP
#define LEET_CODE_SNAPSHOT_ARRAY_HPP

#include <memory>
#include <vector>
#include <unordered_map>

class SnapshotArray {
    struct snapshot {
        int value, id;
    };
    std::vector<std::vector<snapshot>> history_;
    int snap_{0};

public:
    SnapshotArray(int length): history_(length) { }

    void set(int index, int val)
    {
        snapshot change{val, snap_};
        auto& snapshots = history_[index];

        if (snapshots.empty()) {
            if (val) snapshots.emplace_back(change);
        }
        else {
            if (snapshots.back().value!=change.value)
                snapshots.emplace_back(change);
        }
    }

    int snap()
    {
        return snap_++;
    }

    int get(int index, int snap_id)
    {
        auto snapshots = history_[index];
        if (snapshots.empty()) {
            return 0;
        }
        else {
            if (snapshots[0].id>snap_id) return 0;
            for (std::size_t i{1}; i<snapshots.size(); i++)
                if (snapshots[i].id>snap_id) return snapshots[i-1].value;
            return snapshots.back().value;
        }
    }
};

void test_snapshot()
{
//    [[3],[0,5],[],[0,6],[0,0]]
//    auto obj = std::make_unique<SnapshotArray>(3);
//    obj->set(0, 5);
//    s
//    int param_2 = obj->snap();
//    int param_3 = obj->get(index,snap_id);
}

#endif //LEET_CODE_SNAPSHOT_ARRAY_HPP
