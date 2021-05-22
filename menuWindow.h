#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class menuWindow; }
QT_END_NAMESPACE

class menuWindow : public QMainWindow
{
    Q_OBJECT

public:
    menuWindow(QWidget *parent = nullptr);
    ~menuWindow();

private:
    Ui::menuWindow *ui;
};
#endif // MENUWINDOW_H
