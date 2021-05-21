#ifndef CREATEGAMEWINDOW_H
#define CREATEGAMEWINDOW_H

#include <QWidget>
#include "gameWindow3Players.h"

namespace Ui {
class createGameWindow;
}

class createGameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit createGameWindow(QWidget *parent = nullptr);
    ~createGameWindow();

signals:
    void firstwindow();

private slots:
    void on_backWindowButton_clicked();

    void on_startGameButton_clicked();

private:
    Ui::createGameWindow *ui;
    gameWindow3Players *gameWin3P;
};

#endif // CREATEGAMEWINDOW_H
