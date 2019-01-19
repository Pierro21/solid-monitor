//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include "TabView.hpp"

TabView::TabView(const std::vector<DataTypes> &v, QWidget *parent)
    : QGridLayout(parent), _addW(v, parent), _add("Add Widget")
{
    addWidget(&_add);
    QObject::connect(&_add, SIGNAL(clicked()), &_addW, SLOT(show()));
}
