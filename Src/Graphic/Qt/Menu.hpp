//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_MENU_HPP
#define SOLID_MONITOR_MENU_HPP

#include <QtWidgets/QMenuBar>
#include "AddWidget.hpp"

class Menu : public QMenuBar {
    Q_OBJECT
public:
    explicit Menu(const std::vector<DataTypes> &v, QWidget *parent = nullptr);
private:
};

#endif //SOLID_MONITOR_MENU_HPP
