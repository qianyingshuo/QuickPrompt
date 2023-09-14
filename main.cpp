#include "QuickPrompt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuickPrompt w;
    w.show();
    return a.exec();
}
