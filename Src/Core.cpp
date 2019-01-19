//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <memory>
#include <iostream>
#include <vector>
#include <experimental/filesystem>
#include "Core.hpp"
#include "Data.hpp"

core::Core::Core(const std::string &pathToDisplay,
    const std::string &pathToModules
) : _dlmanager(pathToDisplay, pathToModules)
{
    _display = _dlmanager.getDisplay();
    _moduleV = _dlmanager.getModuleV();
}

core::Core::~Core()
{
    _dlmanager.clear();
}

void core::Core::run()
{
    init();
    while (_display->isOpen()) {
        std::unordered_map<std::string, Data> datas({});
        for (auto &i : _moduleV) {
            auto h = i->getModuleData();
            for (auto &j : h) {
                datas[j.getName()] = j;

            }
        }
        _display->process(datas);
    }
}

void core::Core::init()
{
    std::vector<DataTypes> testV;
    for (auto &i : _moduleV) {
        auto t = i->getModuleTypes();
        for (auto &j : t) {
            testV.emplace_back(
                j.getName(), j.isGeneric(), j.isGraph(), j.isHistoGraph());
        }
    }
    _display->init(testV);
}
