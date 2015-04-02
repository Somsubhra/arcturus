#include "viewport.h"

#include "mainwindow.h"

ViewPort::ViewPort(MainWindow* mainWindow, QWidget* parent)
    : QScrollArea(parent)
{
    m_mainWindow = mainWindow;
}

ViewPort::~ViewPort()
{

}

