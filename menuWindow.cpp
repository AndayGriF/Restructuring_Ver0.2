#include "menuWindow.h"
#include "ui_menuWindow.h"

menuWindow::menuWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menuWindow)
{
    ui->setupUi(this);
}

menuWindow::~menuWindow()
{
    delete ui;
}

