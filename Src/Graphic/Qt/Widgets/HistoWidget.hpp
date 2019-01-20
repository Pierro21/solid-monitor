//
// Project: solid_monitor
// Created by Pierre RAMOIN on 20/01/19.
//

#ifndef SOLID_MONITOR_HISTOWIDGET_HPP
#define SOLID_MONITOR_HISTOWIDGET_HPP

#include <QtWidgets/QVBoxLayout>
#include <QChart>
#include <QChartView>
#include <chrono>
#include <QLineSeries>
#include <QValueAxis>
#include "AWidget.hpp"

class HistoWidget : public AWidget {
public:
    explicit HistoWidget(const QString &name, size_t refreshTime = 1,
        QWidget *parent = nullptr
    );
    void process(const Data &data) override;
private:
    QVBoxLayout _layout;
    QtCharts::QLineSeries _series;
    QtCharts::QChart _chart;
    QtCharts::QChartView _chartView;
    std::chrono::time_point<std::chrono::system_clock> _nextUpdate;
    size_t _lasts;
    size_t _refreshTime;
    QtCharts::QValueAxis _axisX;
    QtCharts::QValueAxis _axisY;

    qreal getMax();
};

#endif //SOLID_MONITOR_HISTOWIDGET_HPP
