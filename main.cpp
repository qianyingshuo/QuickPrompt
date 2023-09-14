#include "QuickPrompt.h"

#include <QApplication>
using namespace QP;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QuickPrompt w;
    w.show();
    return a.exec();
}
