//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_IMODULE_HPP
#define SOLID_MONITOR_IMODULE_HPP

#include "Data.hpp"
#include <DataTypes.hpp>

class IModule {
public:
    virtual std::vector<Data> getModuleData() = 0;
    virtual std::vector<DataTypes> getModuleTypes() = 0;
};

#endif //SOLID_MONITOR_IMODULE_HPP
