#include "createGameWindow.h"
#include "ui_createGameWindow.h"
#include "QTimer"

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
    emit firstwindow();
    QEventLoop loop;
    QTimer timer;
    timer.setInterval(500); //5 sec
    connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start();
    loop.exec();
    this->close();
}

void createGameWindow::on_startGameButton_clicked()
{
    gameWin3P->showFullScreen();
    QEventLoop loop;
    QTimer timer;
    timer.setInterval(500); //5 sec
    connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start();
    loop.exec();
    this->close();
}
