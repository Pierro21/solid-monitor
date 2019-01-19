//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_TAB_MANAGER_HPP
#define SOLID_MONITOR_TAB_MANAGER_HPP

#include <QtWidgets/QTabWidget>
#include "types.hpp"
#include "TabView.hpp"
#include "Tab.hpp"

class TabManager : public QTabWidget {
    Q_OBJECT
public:
    explicit TabManager(const std::vector<DataTypes> &v, QWidget *parent);
private:
    std::map<std::string, std::unique_ptr<Tab>> _tabs;
};

#endif //SOLID_MONITOR_TAB_MANAGER_HPP
