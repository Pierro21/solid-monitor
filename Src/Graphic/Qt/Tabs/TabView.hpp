//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_TAB_VIEW_HPP
#define SOLID_MONITOR_TAB_VIEW_HPP

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include "AddWidget.hpp"

class TabView : public QGridLayout {
    Q_OBJECT
public:
    explicit TabView(const std::vector<DataTypes> &v, QWidget *parent);

private:
    AddWidget _addW;
    QPushButton _add;
};

#endif //SOLID_MONITOR_TAB_VIEW_HPP
