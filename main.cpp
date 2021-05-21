#include "menuWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menuWindow w;
    w.showFullScreen();
    w.show();
    return a.exec();
}
