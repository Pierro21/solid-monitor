//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <experimental/filesystem>
#include <iostream>
#include "DLManager.hpp"

core::DLManager::DLManager(const std::string &pathToDisplay,
    const std::string &pathToModules
)
{
    _displayDL = std::make_unique<DLLoader<IDisplayManager>>(pathToDisplay);
    std::cout << "ok display" << std::endl;
    for (const auto & entry :
        std::experimental::filesystem::directory_iterator(pathToModules)) {
        std::string file = entry.path();
        if(file.substr(file.find_last_of('.') + 1) == "so") {
            _moduleDLV.emplace_back(std::make_unique<DLLoader<IModule>>(file));
        }
    }
}

std::shared_ptr<IDisplayManager> core::DLManager::getDisplay()
{
    if (!_displayDL)
        return nullptr;
    return _displayDL->getSharedObject();
}

std::vector<std::shared_ptr<IModule>> core::DLManager::getModuleV()
{
    std::vector<std::shared_ptr<IModule>> res;
    for (auto &i : _moduleDLV) {
        res.emplace_back(i->getSharedObject());
    }
    return res;
}

void core::DLManager::clear()
{
    auto err = _displayDL.release();
    for (auto &i : _moduleDLV)
        auto err2 = i.release();
}
