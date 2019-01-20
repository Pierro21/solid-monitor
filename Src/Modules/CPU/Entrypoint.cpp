//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include "Module.hpp"

extern "C" {
    Module *entryPoint()
    {
        return new Module();
    }
}