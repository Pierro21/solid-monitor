//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <iostream>
#include <Widgets/GeneralWidget.hpp>
#include "Tab.hpp"

Tab::Tab(const std::vector<DataTypes> &v, QWidget *parent): QTabWidget(parent),
_layout(v, this)
{
}

void Tab::insertNew(QTreeWidgetItem *item, int column)
{
    QString typeWidget = item->text(0);
    if (item->parent()) {
        item = item->parent();
        auto typeInfos = item->text(0);
        std::unique_ptr<AWidget> widget;
        if (typeWidget == "infos") {
           widget = std::make_unique<GeneralWidget>(typeInfos, this);
        } else if (typeWidget == "graph")
            widget = std::make_unique<GeneralWidget>(typeInfos, this);
        else
            widget = std::make_unique<GeneralWidget>(typeInfos, this);

        _layout.addWidget(widget.get());
        _widgets[typeInfos.toUtf8().data()] = std::move(widget);
    }
}

void Tab::process(const std::unordered_map<std::string, Data> &data)
{
    for (auto &i : data) {
        if (_widgets[i.first])
            _widgets[i.first]->process(i.second);
    }
}
