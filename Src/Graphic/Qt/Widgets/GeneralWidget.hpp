//
// Project: solid_monitor
// Created by Pierre RAMOIN on 20/01/19.
//

#ifndef SOLID_MONITOR_GENERALWIDGET_HPP
#define SOLID_MONITOR_GENERALWIDGET_HPP

#include <QtWidgets/QLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QLabel>
#include "AWidget.hpp"

class GeneralWidget : public AWidget {
Q_OBJECT
public:
    explicit GeneralWidget(const QString &str = "", QWidget *parent = nullptr);
    void process(const Data &data);

private:
    QVBoxLayout _layout;
    QLabel _text;
};

#endif //SOLID_MONITOR_GENERALWIDGET_HPP
