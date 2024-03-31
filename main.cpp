#include "cinema.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cinema w;
    w.show();
    return a.exec();
}
