#include "gameWindow3Players.h"
#include "ui_gameWindow3Players.h"

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
    emit firstwindow();
}
