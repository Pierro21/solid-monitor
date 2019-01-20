//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <Data.hpp>
#include <fstream>
#include "Module.hpp"

Module::Module()
{
    _types.emplace_back("system", true, false, false);
    _datas.emplace_back("system");
}

std::vector<Data> Module::getModuleData()
{
    std::ifstream version("/proc/version");
    std::string complete;
    std::string tmp;
    while (!version.eof()) {
        complete += static_cast<char>(version.get());
    }

    _datas[0].setGeneralInfo(complete);
    return _datas;
}

std::vector<DataTypes> Module::getModuleTypes()
{
    return _types;
}

