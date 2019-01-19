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
    _display->init(std::vector<std::string>({"toto", "roger"}));
    _display->process(std::unordered_map<std::string, moduleData>());
    while (_display->isOpen())
        _display->process(std::unordered_map<std::string, moduleData>());
}
