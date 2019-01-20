//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <Data.hpp>
#include <fstream>
#include <iostream>
#include "Module.hpp"

Module::Module(): _old(0)
{
    _types.emplace_back("network_received", true, false, true);
    _datas.emplace_back("network_received");
}

std::vector<Data> Module::getModuleData()
{
    std::ifstream net("/proc/net/dev");
    std::string complete;
    std::string name;
    std::string bytesStr;
    if (net) {
        std::getline(net, complete);
        std::getline(net, complete);
        while (std::getline(net, complete)) {
            net >> name;
            net >> bytesStr;
            if (computeData(bytesStr))
                break;
        }
    }
    return _datas;
}

std::vector<DataTypes> Module::getModuleTypes()
{
    return _types;
}

bool Module::computeData(const std::string &bytesStr)
{
    auto bytes = std::strtol(bytesStr.c_str(), nullptr, 10);
    if (bytes > 0) {
        _new += bytes - _old;
        if (_nextUpdate <= std::chrono::system_clock::now()) {
            _datas[0].setGeneralInfo(std::to_string(_new / 1000));
            _new = 0;
            _nextUpdate = std::chrono::system_clock::now() + std::chrono::seconds(1);
        } else
            _old = bytes;
        return true;
    }
    return false;
}

