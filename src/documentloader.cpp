#include "documentloader.h"

DocumentLoader::DocumentLoader(MainWindow* mainWindow, QObject *parent)
    : QObject(parent)
{
    m_mainWindow = mainWindow;
}

DocumentLoader::~DocumentLoader()
{

}

