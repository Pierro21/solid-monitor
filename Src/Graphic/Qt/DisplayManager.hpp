//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_DISPLAYMANAGER_HPP
#define SOLID_MONITOR_DISPLAYMANAGER_HPP

#include "IDisplayManager.hpp"
#include <QApplication>

class DisplayManager : public IDisplayManager {
public:
    DisplayManager();
    void start() override;

private:
    int _args;
    QApplication _qApp;
};

#endif //SOLID_MONITOR_DISPLAYMANAGER_HPP
