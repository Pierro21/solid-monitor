//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QTabWidget>
#include <QObject>
#include <iostream>
#include "DisplayManager.hpp"

DisplayManager::DisplayManager() :
_args(0),
_qApp(_args, nullptr)
{
    _mainWindow.setLayout(&_layout);
    _mainWindow.setGeometry(0, 0, 400, 400);
}

void DisplayManager::process(const std::unordered_map<std::string, Data>
    &datas
)
{
    dynamic_cast<Tab *>(_tabManager->currentWidget())->process(datas);
    _qApp.processEvents();
}

void DisplayManager::init(const std::vector<DataTypes> &availableModules)
{
    _menu = std::make_unique<Menu>(availableModules, &_mainWindow);
    _tabManager = std::make_unique<TabManager>(availableModules, &_mainWindow);
    _layout.addWidget(_menu.get());
    _layout.addWidget(_tabManager.get());
    _mainWindow.show();
}

bool DisplayManager::isOpen() const
{
    return _mainWindow.isVisible();
}

const std::vector<DataTypes> & DisplayManager::getEnableModules() const
{
    return _enableModules;
}
