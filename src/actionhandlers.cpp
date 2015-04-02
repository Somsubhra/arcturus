#include "actionhandlers.h"

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

}

void ActionHandlers::slotOpen()
{

}
