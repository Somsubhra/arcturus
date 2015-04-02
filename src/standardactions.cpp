#include "standardactions.h"
#include "mainwindow.h"
#include "actioncollection.h"
#include "actionhandlers.h"

#include <QAction>
#include <QStyle>

StandardActions::StandardActions(MainWindow *mainWindow, QObject *parent)
    : QObject(parent)
{
    m_mainWindow = mainWindow;

    m_actionHandlers = new ActionHandlers(m_mainWindow, this);
}

StandardActions::~StandardActions()
{
    delete m_actionHandlers;
}

void StandardActions::createStandardActions()
{
    QAction* exitAction = new QAction(tr("Exit"), m_mainWindow);
    exitAction->setShortcut(QKeySequence("Ctrl+Q"));
    m_mainWindow->actionCollection()->addAction("exit", exitAction);
    connect(exitAction, SIGNAL(triggered()), m_actionHandlers, SLOT(slotExit()));

    QAction* openAction = new QAction(m_mainWindow->style()->standardIcon(QStyle::SP_DirOpenIcon),
                                      tr("Open"), m_mainWindow);
    openAction->setShortcut(QKeySequence("Ctrl+O"));
    m_mainWindow->actionCollection()->addAction("open", openAction);
    connect(openAction, SIGNAL(triggered()), m_actionHandlers, SLOT(slotOpen()));
}
