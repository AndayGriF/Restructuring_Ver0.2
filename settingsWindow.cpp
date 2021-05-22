#include "settingsWindow.h"
#include "ui_settingsWindow.h"
#include "QTimer"

settingsWindow::settingsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingsWindow)
{
    ui->setupUi(this);

}

settingsWindow::~settingsWindow()
{
    delete ui;
}

void settingsWindow::on_backMWindowButton_clicked()
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
