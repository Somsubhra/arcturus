#include "mainwindow.h"
#include "actioncollection.h"
#include "standardactions.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_actionCollection = new ActionCollection(this);

    m_standardActions = new StandardActions(this, this);
    m_standardActions->createStandardActions();

    this->createMenuBar();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenuBar()
{

}

ActionCollection* MainWindow::actionCollection()
{
    return m_actionCollection;
}
