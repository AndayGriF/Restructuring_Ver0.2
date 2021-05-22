#include "mainWindow.h"
#include "ui_mainWindow.h"

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    gameWin = new gameWindow();
    connect(gameWin, &gameWindow::firstwindow, this, &mainWindow::show);
}

mainWindow::~mainWindow()
{
    delete ui;
}


void mainWindow::on_shutdownWindow_clicked()
{
    this->close();
}

void mainWindow::on_backMenuWindow_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void mainWindow::on_connectGameButton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
}

void mainWindow::on_startGameButton_clicked()
{
    gameWin->show();
    this->close();
}

void mainWindow::on_runGameButton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
}
