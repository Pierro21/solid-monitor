//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include "Menu.hpp"

Menu::Menu(const std::vector<DataTypes> &v, QWidget *parent) : QMenuBar(parent)
{
    addMenu(QString("Edit"));
}
