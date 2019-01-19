//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_AWIDGET_HPP
#define SOLID_MONITOR_AWIDGET_HPP

#include <QtWidgets/QWidget>
#include "Data.hpp"

class AWidget : public QWidget {
    Q_OBJECT
public:
    explicit AWidget(QWidget *parent = nullptr);
    virtual void process(const Data &data) = 0;
private:

};

#endif //SOLID_MONITOR_AWIDGET_HPP
