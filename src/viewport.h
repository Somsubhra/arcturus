#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QScrollArea>

class MainWindow;

class ViewPort : public QScrollArea
{
public:
    ViewPort(MainWindow* mainWindow, QWidget* parent = 0);
    ~ViewPort();

private:
    MainWindow* m_mainWindow;
};

#endif // VIEWPORT_H
