#ifndef DOCUMENTLOADER_H
#define DOCUMENTLOADER_H

#include <QObject>

class MainWindow;

class DocumentLoader : public QObject
{
    Q_OBJECT
public:
    explicit DocumentLoader(MainWindow* mainWindow, QObject *parent = 0);
    ~DocumentLoader();

signals:

public slots:

private:
    MainWindow* m_mainWindow;
};

#endif // DOCUMENTLOADER_H
