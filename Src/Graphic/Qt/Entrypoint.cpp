//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include "DisplayManager.hpp"

extern "C" {
    DisplayManager *entryPoint()
    {
        return new DisplayManager();
    }
}