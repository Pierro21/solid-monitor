//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <memory>
#include <iostream>
#include <vector>
#include <experimental/filesystem>
#include "Core.hpp"

core::Core::Core(
    const std::string &pathToDisplay,
    const std::string &pathToModules): _dlmanager(pathToDisplay, pathToModules)
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
    std::vector<DataTypes> testV;
    testV.emplace_back("CPU", true, true, true);
    testV.emplace_back("GPU", true, false, true);
    testV.emplace_back("Clock", true, true, false);
    _display->init(testV);
    while (_display->isOpen())
        _display->process(std::unordered_map<std::string, moduleData>());
}
