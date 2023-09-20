#include "QuickPrompt.h"
#include "ui_QuickPrompt.h"
#include <QFile>
#include <QDir>
#include "DataTypeDefine.h"
#include <QTextStream>
#include "singleElement.h"
#include <QAction>
#include "ApplicationSetting.h"
#include <QFileDialog>
#include <QTextCodec>

namespace QP {


QuickPrompt::QuickPrompt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QuickPrompt)
{
    ui->setupUi(this);
    parserAppSetting();
    QAction *setBrowserPath = ui->menubar->addAction(tr("select browser"));
    creatViewByFile();
    this->setWindowIcon(QIcon(":/logo/res/favicon.ico"));
    connect(setBrowserPath, &QAction::triggered, this, &QuickPrompt::setNewBrowserPath);
}

QuickPrompt::~QuickPrompt()
{
    delete ui;
}

void QuickPrompt::setNewBrowserPath()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("select browser"),
                                                    "/home",
                                                    tr("browser (*.exe)"));
    if(!fileName.isNull())
    {
        ApplicationSetting::getInstance()->setBrowserPath(fileName);
        m_appSet->setValue("browserPath", fileName);
        m_appSet->sync();
    }
}

void QuickPrompt::parserAppSetting()
{

    QString fileName = QCoreApplication::applicationDirPath() + "/qp.ini";
    if(!m_appSet)
    {
        m_appSet = new QSettings(fileName, QSettings::IniFormat);
        m_appSet->setIniCodec(QTextCodec::codecForName("UTF-8"));
    }
    if(m_appSet->contains("browserPath") && true != m_appSet->value("browserPath").isNull())
    {
        ApplicationSetting::getInstance()->setBrowserPath(m_appSet->value("browserPath").toString());
    }
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
    QFile qssfile(":/qss/res/MacOS.qss");
    qssfile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(qssfile.readAll());
    this->setStyleSheet(styleSheet);
}

}
