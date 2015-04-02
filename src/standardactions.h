#ifndef STANDARDACTIONS_H
#define STANDARDACTIONS_H

#include <QObject>

class MainWindow;
class ActionHandlers;

class StandardActions : public QObject
{
    Q_OBJECT
public:
    explicit StandardActions(MainWindow* mainWindow, QObject *parent = 0);
    ~StandardActions();

    void createStandardActions();

signals:

public slots:

private:
    MainWindow* m_mainWindow;
    ActionHandlers* m_actionHandlers;
};

#endif // STANDARDACTIONS_H
