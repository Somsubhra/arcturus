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

signals:

public slots:
    void loadDocument(QString file);

private:
    MainWindow* m_mainWindow;
    Poppler::Document* m_document;
    QList<QImage>* m_pages;
};

#endif // DOCUMENTLOADER_H
