#include "mainwindow.h"
#include "actioncollection.h"
#include "standardactions.h"
#include "documentloader.h"

#include <QMenuBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowState(Qt::WindowMaximized);
    this->setMinimumSize(400, 300);

    m_actionCollection = new ActionCollection(this);

    m_standardActions = new StandardActions(this, this);
    m_standardActions->createStandardActions();

    createMenuBar();

    m_documentLoader = new DocumentLoader(this, this);
}

MainWindow::~MainWindow()
{
    delete m_actionCollection;
    delete m_standardActions;
    delete m_documentLoader;
}

void MainWindow::createMenuBar()
{
    QMenu* fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(m_actionCollection->action("open"));
    fileMenu->addSeparator();
    fileMenu->addAction(m_actionCollection->action("exit"));

    QMenu* helpMenu = this->menuBar()->addMenu(tr("Help"));
    helpMenu->addAction(m_actionCollection->action("help"));
    helpMenu->addSeparator();
    helpMenu->addAction(m_actionCollection->action("about"));
}

ActionCollection* MainWindow::actionCollection()
{
    return m_actionCollection;
}

DocumentLoader* MainWindow::documentLoader()
{
    return m_documentLoader;
}
