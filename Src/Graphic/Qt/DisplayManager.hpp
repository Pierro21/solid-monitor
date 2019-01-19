//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_DISPLAYMANAGER_HPP
#define SOLID_MONITOR_DISPLAYMANAGER_HPP

#include "IDisplayManager.hpp"
#include <QApplication>
#include <QtWidgets>
#include <memory>

class DisplayManager : public IDisplayManager {
public:
    DisplayManager();
    ~DisplayManager() override = default;
    void process(std::unordered_map<std::string, moduleData> datas) override;
    void init(const std::vector<std::string> &availableModules) override;
    bool isOpen() const override;

    const std::vector<std::string> &getEnableModules() const override;

private:
    int _args;
    QApplication _qApp;
    QWidget _mainWindow;
    QPushButton _edit;
    QTabWidget _tabList;
    std::map<std::string, std::unique_ptr<QWidget>> _tabs;
    QVBoxLayout _layout;
    std::vector<std::string> _availableModules;
    std::vector<std::string> _enableModules;
};

#endif //SOLID_MONITOR_DISPLAYMANAGER_HPP
