//
// Project: solid_monitor
// Created by Pierre RAMOIN on 20/01/19.
//

#include <QValueAxis>
#include <iostream>
#include "HistoWidget.hpp"


HistoWidget::HistoWidget(const QString &name, size_t refreshTime,
    QWidget *parent
) : AWidget(parent),
_chartView(&_chart), _nextUpdate(std::chrono::system_clock::now()), _refreshTime(
        refreshTime)
{
    _chart.legend()->setVisible(false);
    _chart.setTitle(name);
    _chart.addSeries(&_series);
    _chart.addAxis(&_axisX, Qt::AlignBottom);
    _chart.addAxis(&_axisY, Qt::AlignLeft);
    _series.attachAxis(&_axisX);
    _series.attachAxis(&_axisY);
    _axisY.setLabelFormat("%d");
    _layout.addWidget(&_chartView);
    setLayout(&_layout);
}

void HistoWidget::process(const Data &data)
{
    if (_nextUpdate < std::chrono::system_clock::now()) {
        auto nbr = std::strtol(
                    data.getGeneralInfo().c_str(), nullptr, 10);
        std::cout << nbr << "; " << _series.count() << std::endl;
        _series << QPoint(_lasts, nbr);
        _axisX.setMax(_lasts);
        _axisY.setMax(getMax());
        _axisX.setVisible(false);
        if (_series.count() > 30) {
            _series.remove(0);
            _axisX.setMin(_axisX.min() + 1);
        }
        _lasts++;
        _nextUpdate = std::chrono::system_clock::now() + std::chrono::seconds(_refreshTime);
    }
}

qreal HistoWidget::getMax()
{
    qreal max = 0;
    for (auto &i : _series.points()) {
        if (i.y() > max)
            max = i.y();
    }
    return max;
}
