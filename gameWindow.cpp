#include "gameWindow.h"
#include "ui_gameWindow.h"

gameWindow::gameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameWindow)
{
    ui->setupUi(this);
}

gameWindow::~gameWindow()
{
    delete ui;
}
