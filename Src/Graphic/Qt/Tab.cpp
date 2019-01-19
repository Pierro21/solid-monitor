//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <iostream>
#include "Tab.hpp"

Tab::Tab(const std::vector<DataTypes> &v, QWidget *parent): QTabWidget(parent),
_layout(v, this)
{
}

void Tab::insertNew(QTreeWidgetItem *item, int column)
{
    QString str = item->text(0);
    while (item->parent()) {
        item = item->parent();
        str += "/" + item->text(0);
    }
    auto p = std::make_unique<QPushButton>(str);
    _layout.addWidget(p.get());
    _widgets[str.toUtf8().data()] = std::move(p);
}

void Tab::process(const std::unordered_map<std::string, Data> &data)
{
    for (auto &i : data) {
        if (_widgets[i.first])
            _widgets[i.first]->setText(QString(i.second.getGeneralInfo().c_str()));
    }
}
