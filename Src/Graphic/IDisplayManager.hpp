//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_IDISPLAYMANAGER_HPP
#define SOLID_MONITOR_IDISPLAYMANAGER_HPP

class IDisplayManager {
public:
    virtual ~IDisplayManager() = 0;
    virtual void start() = 0;
};

#endif //SOLID_MONITOR_IDISPLAYMANAGER_HPP
