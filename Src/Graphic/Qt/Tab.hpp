//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_TAB_HPP
#define SOLID_MONITOR_TAB_HPP

#include <QtWidgets/QTabWidget>
#include <DataTypes.hpp>
#include "TabView.hpp"

class Tab : public QTabWidget {
    Q_OBJECT
public:
    explicit Tab(const std::vector<DataTypes> &v, QWidget *parent = nullptr);
public slots:
    void insertNew(QTreeWidgetItem *item, int column);
private:
    TabView _layout;
    std::vector<std::unique_ptr<QPushButton>> _widgets;
};

#endif //SOLID_MONITOR_TAB_HPP
