#include "QuickPrompt.h"
#include "ui_QuickPrompt.h"
#include <QFile>
#include <QDir>
#include "DataTypeDefine.h"
#include <QTextStream>
#include "singleElement.h"

namespace QP {


QuickPrompt::QuickPrompt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QuickPrompt)
{
    ui->setupUi(this);
    creatViewByFile();
}

QuickPrompt::~QuickPrompt()
{
    delete ui;
}

void QuickPrompt::creatViewByFile()
{
    QString fileName = QCoreApplication::applicationDirPath() + "/configure.prompt";
    QFile file(fileName);
    if(!file.exists())
        return;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);
    in.setCodec("UTF-8");

    QList<element> eles;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        if(line.isEmpty())
            continue;
        if(line.startsWith("ELEMENT_BEGIN"))
        {
            line = line.simplified();
            line.remove("\r\n");
            line.remove("\n");
            element wait2append;
            QStringList singleE = line.split(" ",Qt::SkipEmptyParts);
            if(singleE.size() >= 2)
            {
               wait2append.title = singleE[1];
            }
            QStringList promptStr;
            while (!in.atEnd())
            {
                QString prompt = in.readLine();
                if(prompt.startsWith("ELEMENT_END"))
                {
                    wait2append.contentBase = promptStr.join("\n");
                    eles.append(wait2append);
                    break;
                }

                promptStr.append(prompt);
            }

        }
    }

    for(auto i : eles)
    {
        singleElement* eleWidget = new singleElement(i, this);
        if(isRight)
        {
            ui->rightLayout->insertWidget(ui->rightLayout->count() - 1, eleWidget);
        }
        else
        {
            ui->leftLayout->insertWidget(ui->rightLayout->count() - 1,eleWidget);
        }
        isRight = !isRight;
    }
}

}
