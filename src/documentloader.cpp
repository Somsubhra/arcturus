#include "documentloader.h"
#include "mainwindow.h"

#include <QMessageBox>

DocumentLoader::DocumentLoader(MainWindow* mainWindow, QObject *parent)
    : QObject(parent)
    , m_document(0)
{
    m_mainWindow = mainWindow;
}

DocumentLoader::~DocumentLoader()
{
    if(m_document) {
        delete m_document;
    }
}

void DocumentLoader::loadDocument(QString file)
{
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
}
