//
// Project: solid_monitor
// Created by Pierre RAMOIN on 20/01/19.
//

#include "GeneralWidget.hpp"

GeneralWidget::GeneralWidget(const QString &str, QWidget *parent) : AWidget(parent)
{
    _text.setAlignment(Qt::AlignCenter);
    _layout.addWidget(&_text);
    setLayout(&_layout);
}

void GeneralWidget::process(const Data &data)
{
    _text.setText(QString(data.getGeneralInfo().c_str()));
}
