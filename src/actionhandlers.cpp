#include "actionhandlers.h"
#include "mainwindow.h"

ActionHandlers::ActionHandlers(MainWindow *mainWindow, QObject *parent)
    : QObject(parent)
{
    m_mainWindow = mainWindow;
}

ActionHandlers::~ActionHandlers()
{

}

void ActionHandlers::slotExit()
{
    m_mainWindow->close();
}

void ActionHandlers::slotOpen()
{

}

void ActionHandlers::slotHelp()
{

}

void ActionHandlers::slotAbout()
{

}
