#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "settingsWindow.h"
#include "createGameWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class menuWindow; }
QT_END_NAMESPACE

class menuWindow : public QMainWindow
{
    Q_OBJECT

public:
    menuWindow(QWidget *parent = nullptr);
    ~menuWindow();

private slots:
    void on_exitGButton_clicked();

    void on_settingsGButton_clicked();

    void on_createGButton_clicked();

    void on_connectGButton_clicked();

private:
    Ui::menuWindow *ui;
    settingsWindow *setWin;
    createGameWindow *cGamWin;
};
#endif // MENUWINDOW_H
