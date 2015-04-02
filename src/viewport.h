#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <QScrollArea>
#include <QWidget>

class MainWindow;

class ViewPort : public QScrollArea
{
public:
    ViewPort(MainWindow* mainWindow, QWidget* parent = 0);
    ~ViewPort();

public slots:
    void renderPages(QList<QImage>* pages);

private:
    MainWindow* m_mainWindow;
    QWidget* m_mainWidget;
};

#endif // VIEWPORT_H
