#include "QuickPrompt.h"
#include <QTranslator>

#include <QApplication>
using namespace QP;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 加载翻译文件:Start
    static QTranslator translator;
    if (translator.load(":/tr/QucikPrompt_zh.qm")) {
        qApp->installTranslator(&translator);
    }
    // 加载翻译文件:End

    QCoreApplication::setOrganizationName("QP");
    QCoreApplication::setOrganizationDomain("qp.com");
    QCoreApplication::setApplicationName("QuickPrompt");
    QuickPrompt w;
    w.show();
    return a.exec();
}
