#include "menuWindow.h"
#include "ui_menuWindow.h"
#include "Windows.h"
#include "QTimer"

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
    setWin->showFullScreen();
    QEventLoop loop;
    QTimer timer;
    timer.setInterval(500); //5 sec
    connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start();
    loop.exec();
    this->close();
}

void menuWindow::on_createGButton_clicked()
{
    cGamWin->showFullScreen();
    QEventLoop loop;
    QTimer timer;
    timer.setInterval(500); //5 sec
    connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start();
    loop.exec();
    this->close();
}

void menuWindow::on_connectGButton_clicked()
{
    cGamWin->showFullScreen();
    QEventLoop loop;
    QTimer timer;
    timer.setInterval(500); //5 sec
    connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start();
    loop.exec();
    this->close();
}
