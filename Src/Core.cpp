//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <memory>
#include <iostream>
#include <experimental/filesystem>
#include "Core.hpp"

core::Core::Core(
    const std::string &pathToDisplay,
    const std::string &pathToModules): _dlmanager(pathToDisplay, pathToModules)
{
    _display = _dlmanager.getDisplay();
    _moduleV = _dlmanager.getModuleV();
}

void core::Core::run()
{

}
