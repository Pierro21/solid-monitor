//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <ctime>
#include <chrono>
#include <Data.hpp>
#include "Module.hpp"

Module::Module()
{
    _types.emplace_back("clock", true, false, false);
    _datas.setName("clock");
}

std::vector<Data> Module::getModuleData()
{
    auto time = std::chrono::system_clock::
        to_time_t(std::chrono::system_clock::now());
    _datas.setGeneralInfo(std::ctime(&time));
    std::vector<Data> vector;
    vector.emplace_back(_datas);
    return std::move(vector);
}

std::vector<DataTypes> Module::getModuleTypes()
{
    return _types;
}

