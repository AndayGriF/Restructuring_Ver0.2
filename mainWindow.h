#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "gameWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();

private slots:
    void on_shutdownWindow_clicked();

    void on_backMenuWindow_clicked();

    void on_connectGameButton_clicked();

    void on_startGameButton_clicked();

    void on_runGameButton_clicked();

private:
    Ui::mainWindow *ui;
    gameWindow *gameWin;
};
#endif // MENUWINDOW_H
