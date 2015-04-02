#ifndef DOCUMENTLOADER_H
#define DOCUMENTLOADER_H

#include <QObject>
#include <poppler/qt5/poppler-qt5.h>

class MainWindow;

class DocumentLoader : public QObject
{
    Q_OBJECT
public:
    explicit DocumentLoader(MainWindow* mainWindow, QObject *parent = 0);
    ~DocumentLoader();

    void loadDocument(QString file);

signals:

public slots:

private:
    MainWindow* m_mainWindow;
    Poppler::Document* m_document;
};

#endif // DOCUMENTLOADER_H
