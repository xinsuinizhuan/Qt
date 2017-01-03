#include "MainWidget.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    MainWidget w;
    QRect desktopRect = QApplication::desktop()->availableGeometry();
    QPoint center = desktopRect.center();
    w.move(center.x()-w.width()*0.5, center.y()-w.height()*0.5);
    w.show();

    return a.exec();
}