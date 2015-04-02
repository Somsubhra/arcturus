#include "standardactions.h"
#include "mainwindow.h"
#include "actionhandlers.h"

StandardActions::StandardActions(MainWindow *mainWindow, QObject *parent)
    : QObject(parent)
{
    m_mainWindow = mainWindow;

    m_actionHandlers = new ActionHandlers(m_mainWindow, this);
}

StandardActions::~StandardActions()
{

}

void StandardActions::createStandardActions()
{

}
