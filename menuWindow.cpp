#include "menuWindow.h"
#include "ui_menuWindow.h"

menuWindow::menuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menuWindow)
{
    ui->setupUi(this);
    setWin = new settingsWindow();
    connect(setWin, &settingsWindow::firstwindow, this, &menuWindow::show);
    cGamWin = new createGameWindow();
    connect(cGamWin, &createGameWindow::firstwindow, this, &menuWindow::show);
}

menuWindow::~menuWindow()
{
    delete ui;
}


void menuWindow::on_exitGButton_clicked()
{
    this->close();
}

void menuWindow::on_settingsGButton_clicked()
{
    setWin->show();
    this->close();
}

void menuWindow::on_createGButton_clicked()
{
    cGamWin->show();
    this->close();
}
