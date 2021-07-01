#include "mainmenu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu mm;
    mm.setWindowTitle("Arcanoid");
    mm.setFixedSize(WIDTH, HEIGHT);
    mm.show();
    return a.exec();
}
