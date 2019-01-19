//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#ifndef SOLID_MONITOR_ADDWIDGET_HPP
#define SOLID_MONITOR_ADDWIDGET_HPP

#include <QtWidgets/QDialog>
#include <QtWidgets/QTreeWidget>
#include <QStringListModel>
#include <QHBoxLayout>
#include <memory>
#include <QtWidgets/QColumnView>
#include <QtGui/QStandardItemModel>
#include "DataTypes.hpp"

class AddWidget : public QDialog {
    Q_OBJECT
public:
    explicit AddWidget(const std::vector<DataTypes> &v,
        QWidget *parent = nullptr,
        const char *name = nullptr);

private:
    QTreeWidget _tree;
    std::vector<std::unique_ptr<QTreeWidgetItem>> _items;
    QHBoxLayout _layout;
};

#endif //SOLID_MONITOR_ADDWIDGET_HPP
