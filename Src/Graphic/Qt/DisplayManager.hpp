//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_DISPLAYMANAGER_HPP
#define SOLID_MONITOR_DISPLAYMANAGER_HPP

#include "IDisplayManager.hpp"
#include "AddWidget.hpp"
#include "Menu.hpp"
#include "TabManager.hpp"
#include <QApplication>
#include <QtWidgets>
#include <memory>

class DisplayManager : public IDisplayManager {
public:
    DisplayManager();
    ~DisplayManager() override = default;
    void process(const std::unordered_map<std::string, moduleData> &datas)
    override;
    void init(const std::vector<DataTypes> &availableModules) override;
    bool isOpen() const override;

    const std::vector<DataTypes> & getEnableModules() const override;

private:
    int _args;
    QApplication _qApp;
    QWidget _mainWindow;
    std::unique_ptr<Menu> _menu;
    std::unique_ptr<TabManager> _tabList;
    QVBoxLayout _layout;
    std::vector<DataTypes> _availableModules;
    std::vector<DataTypes> _enableModules;
};

#endif //SOLID_MONITOR_DISPLAYMANAGER_HPP
