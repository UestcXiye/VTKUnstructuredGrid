#include "myUnstructuredGrid.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    myUnstructuredGrid w;
    w.show();
    return a.exec();
}
