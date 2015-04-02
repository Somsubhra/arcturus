#include "mainwindow.h"
#include "actioncollection.h"
#include "standardactions.h"
#include "documentloader.h"
#include "viewport.h"

#include <QMenuBar>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowState(Qt::WindowMaximized);
    this->setMinimumSize(400, 300);

    m_actionCollection = new ActionCollection(this);

    m_standardActions = new StandardActions(this, this);
    m_standardActions->createStandardActions();

    createMenuBar();

    m_documentLoader = new DocumentLoader(this, this);

    QWidget* mainWidget = new QWidget(this);
    QGridLayout* mainLayout = new QGridLayout(mainWidget);

    m_viewPort = new ViewPort(this, mainWidget);
    mainLayout->addWidget(m_viewPort, 0, 0);

    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    delete m_actionCollection;
    delete m_standardActions;
    delete m_documentLoader;
    delete m_viewPort;
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

ViewPort* MainWindow::viewPort()
{
    return m_viewPort;
}
