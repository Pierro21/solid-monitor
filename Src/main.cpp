//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include "Core.hpp"

int main(int ac, char **av)
{
    std::string toto("../Libs/Modules");
    std::string popo("../Libs/Graphic/libQtDisplayManager.so");
    core::Core core(popo, toto);
    core.run();
}