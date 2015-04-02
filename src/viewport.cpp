#include "viewport.h"
#include "mainwindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QPixmap>

ViewPort::ViewPort(MainWindow* mainWindow, QWidget* parent)
    : QScrollArea(parent)
    , m_mainWidget(0)
{
    m_mainWindow = mainWindow;
}

ViewPort::~ViewPort()
{
    if(m_mainWidget) {
        delete m_mainWidget;
    }
}

void ViewPort::renderPages(QList<QImage>* pages)
{
    if(m_mainWidget) {
        delete m_mainWidget;
        m_mainWidget = 0;
    }

    m_mainWidget = new QWidget(this);
    QGridLayout* mainLayout = new QGridLayout(m_mainWidget);

    int numberOfPages = pages->length();

    for(int pageNumber = 0; pageNumber < numberOfPages; pageNumber++) {
        QLabel* page = new QLabel(m_mainWidget);
        page->setPixmap(QPixmap::fromImage(pages->at(pageNumber)));

        mainLayout->addWidget(page, pageNumber, 0);
    }

    m_mainWidget->setLayout(mainLayout);
    setWidget(m_mainWidget);
}
