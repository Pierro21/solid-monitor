//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTabWidget>
#include <iostream>
#include "DisplayManager.hpp"

DisplayManager::DisplayManager() :
_args(0),
_qApp(_args, nullptr),
_edit("Edit")
{
//    QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    _layout.addWidget(&_edit);
    _layout.addWidget(&_tabList);
    _mainWindow.setLayout(&_layout);
}

void DisplayManager::process(std::unordered_map<std::string, moduleData> datas)
{
    _mainWindow.show();
    _qApp.processEvents();
}

void DisplayManager::init(const std::vector<std::string> &availableModules)
{
    _availableModules = availableModules;
}

bool DisplayManager::isOpen() const
{
    return _mainWindow.isVisible();
}

const std::vector<std::string> &DisplayManager::getEnableModules() const
{
    return _enableModules;
}
