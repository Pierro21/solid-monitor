//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include "TabManager.hpp"


TabManager::TabManager(const std::vector<DataTypes> &v,
    QWidget *parent) : QTabWidget(parent)
{
    auto dash = std::make_unique<Tab>(v, this);
    addTab(dash.get(), "dashboard");
    _tabs.emplace("dashboard", std::move(dash));
    auto core = std::make_unique<Tab>(v, this);
    addTab(core.get(), "core");
    _tabs.emplace("core", std::move(core));

}
