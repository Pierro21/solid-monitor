//
// Project: solid_monitor
// Created by Pierre RAMOIN on 19/01/19.
//

#include <QtWidgets/QApplication>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include "DisplayManager.hpp"

void DisplayManager::start()
{
}

DisplayManager::DisplayManager() : _args(0), _qApp(_args, nullptr)
{

    auto *textEdit = new QTextEdit;
    QPushButton *quitButton = new QPushButton("&Quit");

    QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    auto *layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(quitButton);

    QWidget window;
    window.setLayout(layout);

    window.show();
    _qApp.exec();
}
