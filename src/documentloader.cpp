#include "documentloader.h"
#include "mainwindow.h"
#include "viewport.h"

#include <QMessageBox>

DocumentLoader::DocumentLoader(MainWindow* mainWindow, QObject *parent)
    : QObject(parent)
    , m_document(0)
{
    m_mainWindow = mainWindow;
    m_pages = new QList<QImage>();
}

DocumentLoader::~DocumentLoader()
{
    if(m_document) {
        delete m_document;
    }

    delete m_pages;
}

void DocumentLoader::loadDocument(QString file)
{
    m_pages->clear();

    m_document = Poppler::Document::load(file);

    if(!m_document) {
        QMessageBox errorBox;
        errorBox.critical(m_mainWindow, tr("Arcturus Error"), tr("Could not open file."));
        errorBox.setFixedSize(500, 200);

        delete m_document;
        m_document = 0;

        return;
    }

    if(m_document->isLocked()) {
        QMessageBox passwordBox;
        passwordBox.critical(m_mainWindow, tr("Password protected"), tr("This document is password protected"));
        passwordBox.setFixedSize(500, 200);

        delete m_document;
        m_document = 0;

        return;
    }

    int numberOfPages = m_document->numPages();

    for(int pageNumber = 0; pageNumber < numberOfPages; pageNumber++) {
        Poppler::Page* pdfPage = m_document->page(pageNumber);

        if(pdfPage == 0) {
            continue;
        }

        QImage image = pdfPage->renderToImage();

        if(image.isNull()) {
            continue;
        }

        m_pages->append(image);

        delete pdfPage;
    }

    delete m_document;
    m_document = 0;

    m_mainWindow->viewPort()->renderPages(m_pages);
}
