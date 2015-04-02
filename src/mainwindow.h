#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ActionCollection;
class StandardActions;
class DocumentLoader;
class ViewPort;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    ActionCollection* actionCollection();

    DocumentLoader* documentLoader();

    ViewPort* viewPort();

private:
    void createMenuBar();

signals:

public slots:

private:
    ActionCollection* m_actionCollection;
    StandardActions* m_standardActions;
    DocumentLoader* m_documentLoader;
    ViewPort* m_viewPort;
};

#endif // MAINWINDOW_H
