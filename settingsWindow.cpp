#include "settingsWindow.h"
#include "ui_settingsWindow.h"

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
    this->close();
    emit firstwindow();
}
