#ifndef GAMEWINDOW3PLAYERS_H
#define GAMEWINDOW3PLAYERS_H

#include <QWidget>

namespace Ui {
class gameWindow3Players;
}

class gameWindow3Players : public QWidget
{
    Q_OBJECT

public:
    explicit gameWindow3Players(QWidget *parent = nullptr);
    ~gameWindow3Players();

signals:
    void firstwindow();

private slots:
    void on_backWindowButton_clicked();

private:
    Ui::gameWindow3Players *ui;
};

#endif // GAMEWINDOW3PLAYERS_H
