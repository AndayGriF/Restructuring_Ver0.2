#include "createGameWindow.h"
#include "ui_createGameWindow.h"

createGameWindow::createGameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createGameWindow)
{
    ui->setupUi(this);
    gameWin3P = new gameWindow3Players();
    connect(gameWin3P, &gameWindow3Players::firstwindow, this, &createGameWindow::show);
}

createGameWindow::~createGameWindow()
{
    delete ui;
}

void createGameWindow::on_backWindowButton_clicked()
{
    this->close();
    emit firstwindow();
}

void createGameWindow::on_startGameButton_clicked()
{
    gameWin3P->show();
    this->close();
}
