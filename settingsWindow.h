#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QWidget>

namespace Ui {
class settingsWindow;
}

class settingsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit settingsWindow(QWidget *parent = nullptr);
    ~settingsWindow();

signals:
    void firstwindow();

private slots:
    void on_backMWindowButton_clicked();

private:
    Ui::settingsWindow *ui;
};

#endif // SETTINGSWINDOW_H
