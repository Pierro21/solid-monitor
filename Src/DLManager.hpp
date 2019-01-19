//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_DLMANAGER_HPP
#define SOLID_MONITOR_DLMANAGER_HPP

#include <string>
#include <memory>
#include <vector>
#include "DLLoader.hpp"
#include "IDisplayManager.hpp"
#include "IModule.hpp"

namespace core {
    class DLManager {
    public:
        DLManager(const std::string &pathToDisplay,
            const std::string &pathToModules
        );
        std::shared_ptr<IDisplayManager> getDisplay();
        std::vector<std::shared_ptr<IModule>> getModuleV();
        void clear();
    private:
        std::unique_ptr<DLLoader<IDisplayManager>> _displayDL;
        std::vector<std::unique_ptr<DLLoader<IModule>>> _moduleDLV;
    };
}

#endif //SOLID_MONITOR_DLMANAGER_HPP
