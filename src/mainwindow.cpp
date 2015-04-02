#include "mainwindow.h"
#include "actioncollection.h"
#include "standardactions.h"

#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowState(Qt::WindowMaximized);
    this->setMinimumSize(400, 300);

    m_actionCollection = new ActionCollection(this);

    m_standardActions = new StandardActions(this, this);
    m_standardActions->createStandardActions();

    createMenuBar();
}

MainWindow::~MainWindow()
{
    delete m_actionCollection;
    delete m_standardActions;
}

void MainWindow::createMenuBar()
{
    QMenu* fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(m_actionCollection->action("open"));
    fileMenu->addSeparator();
    fileMenu->addAction(m_actionCollection->action("exit"));
}

ActionCollection* MainWindow::actionCollection()
{
    return m_actionCollection;
}
