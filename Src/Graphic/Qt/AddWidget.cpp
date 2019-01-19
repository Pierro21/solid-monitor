//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <iostream>
#include "DataTypes.hpp"
#include "AddWidget.hpp"

AddWidget::AddWidget(
    const std::vector<DataTypes> &v,
    QWidget *parent,
    const char *name)
:QDialog(parent)
{
    for (auto &i : v) {
        auto item = std::make_unique<QTreeWidgetItem>();
        if (i.isGeneric()) {
            auto subItem = std::make_unique<QTreeWidgetItem>();
            subItem->setText(0, "infos");
            item->addChild(subItem.get());
            _items.emplace_back(std::move(subItem));
        }
        if (i.isGraph()) {
            auto subItem = std::make_unique<QTreeWidgetItem>();
            subItem->setText(0, "graph");
            item->addChild(subItem.get());
            _items.emplace_back(std::move(subItem));
        }
        if (i.isHistoGraph()) {
            auto subItem = std::make_unique<QTreeWidgetItem>();
            subItem->setText(0, "histograph");
            item->addChild(subItem.get());
            _items.emplace_back(std::move(subItem));
        }
        item->setText(0, i.getName().c_str());
        _tree.addTopLevelItem(item.get());
        _items.emplace_back(std::move(item));
    }
    connect(&_tree,
        SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)),
            parent, SLOT(insertNew(QTreeWidgetItem *, int)));
    _layout.addWidget(&_tree);
    setLayout(&_layout);
}
