//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_TAB_HPP
#define SOLID_MONITOR_TAB_HPP

#include <QtWidgets/QTabWidget>
#include <unordered_map>
#include "DataTypes.hpp"
#include "Data.hpp"
#include "TabView.hpp"

class Tab : public QTabWidget {
    Q_OBJECT
public:
    explicit Tab(const std::vector<DataTypes> &v, QWidget *parent = nullptr);
public slots:
    void insertNew(QTreeWidgetItem *item, int column);
    void process(const std::unordered_map<std::string, Data> &data);
private:
    TabView _layout;
    std::unordered_map<std::string, std::unique_ptr<QPushButton>> _widgets;
};

#endif //SOLID_MONITOR_TAB_HPP
