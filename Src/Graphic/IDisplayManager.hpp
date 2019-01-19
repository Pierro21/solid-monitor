//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_IDISPLAYMANAGER_HPP
#define SOLID_MONITOR_IDISPLAYMANAGER_HPP

#include <unordered_map>
#include "types.hpp"

class IDisplayManager {
public:
    virtual ~IDisplayManager() = 0;
    virtual void process(std::unordered_map<std::string, moduleData> datas) = 0;
    virtual bool isOpen() const = 0;
    virtual void init(const std::vector<std::string> &availableModules) = 0;
    virtual const std::vector<std::string> &getEnableModules() const = 0;
};

#endif //SOLID_MONITOR_IDISPLAYMANAGER_HPP
