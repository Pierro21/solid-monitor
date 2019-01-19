//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_CORE_HPP
#define SOLID_MONITOR_CORE_HPP

#include <vector>
#include "IDisplayManager.hpp"
#include "IModule.hpp"
#include "DLLoader.hpp"
#include "DLManager.hpp"

namespace core {
    class Core {
    public:
        explicit Core(const std::string &pathToDisplay,
            const std::string &pathToModules
        );

        void run();

    private:
        std::shared_ptr<IDisplayManager> _display;
        std::vector<std::shared_ptr<IModule>> _moduleV;
        DLManager _dlmanager;
    };
}

#endif //SOLID_MONITOR_CORE_HPP
