#include "actionhandlers.h"
#include "mainwindow.h"

#include <QFileDialog>
#include <QStandardPaths>

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
    QString documentDir = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation).at(0);
    QString filter = tr("Portable Document Format Files (*.pdf)");

    QString file = QFileDialog::getOpenFileName(m_mainWindow,
                                                    tr("Open Document"),
                                                    documentDir,
                                                    filter);
}

void ActionHandlers::slotHelp()
{

}

void ActionHandlers::slotAbout()
{

}
