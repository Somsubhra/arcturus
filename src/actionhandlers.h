#ifndef ACTIONHANDLERS_H
#define ACTIONHANDLERS_H

#include <QObject>

class MainWindow;

class ActionHandlers : public QObject
{
    Q_OBJECT
public:
    explicit ActionHandlers(MainWindow* mainWindow, QObject *parent = 0);
    ~ActionHandlers();

signals:

public slots:
    void slotExit();
    void slotOpen();

    void slotHelp();
    void slotAbout();

private:
    MainWindow* m_mainWindow;
};

#endif // ACTIONHANDLERS_H
