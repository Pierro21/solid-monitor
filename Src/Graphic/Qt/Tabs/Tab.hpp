//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_TAB_HPP
#define SOLID_MONITOR_TAB_HPP

#include <QtWidgets/QTabWidget>
#include <unordered_map>
#include <Widgets/AWidget.hpp>
#include "DataTypes.hpp"
#include "Data.hpp"
#include "TabView.hpp"

class Tab : public QTabWidget {
    Q_OBJECT
public:
    explicit Tab(const std::vector<DataTypes> &v, QWidget *parent = nullptr);
    void process(const std::unordered_map<std::string, Data> &data);
public slots:
    void insertNew(QTreeWidgetItem *item, int column);
private:
    TabView _layout;
    std::unordered_map<std::string, std::unique_ptr<AWidget>> _widgets;
};

#endif //SOLID_MONITOR_TAB_HPP
