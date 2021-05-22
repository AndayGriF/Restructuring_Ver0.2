#include "gameWindow3Players.h"
#include "ui_gameWindow3Players.h"
#include "QTimer"

gameWindow3Players::gameWindow3Players(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameWindow3Players)
{
    ui->setupUi(this);
}

gameWindow3Players::~gameWindow3Players()
{
    delete ui;
}

void gameWindow3Players::on_backWindowButton_clicked()
{
    this->close();
    QEventLoop loop;
    QTimer timer;
    timer.setInterval(500); //5 sec
    connect (&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start();
    loop.exec();
    emit firstwindow();
}
