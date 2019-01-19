//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_TYPES_HPP
#define SOLID_MONITOR_TYPES_HPP

#include <string>
#include <memory>
#include <vector>

struct graphData {
    float min;
    float max;
    float actual;
};

struct moduleData {
    std::string name;
    std::string generalInfo;
    std::unique_ptr<graphData> globalRange;
    std::vector<float> history;
    std::vector<moduleData> subModule;
};

#endif //SOLID_MONITOR_TYPES_HPP
