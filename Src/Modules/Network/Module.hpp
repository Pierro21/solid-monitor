//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_MODULE_HPP
#define SOLID_MONITOR_MODULE_HPP

#include <chrono>
#include "IModule.hpp"

class Module : public IModule {
public:
    Module();
    std::vector<Data> getModuleData() override;
    std::vector<DataTypes> getModuleTypes() override;
private:
    bool computeData(const std::string &bytesStr);
private:
    std::vector<Data> _datas;
    std::vector<DataTypes> _types;
    long _old;
    long _new;
    std::chrono::time_point<std::chrono::system_clock> _nextUpdate;
};

#endif //SOLID_MONITOR_MODULE_HPP
