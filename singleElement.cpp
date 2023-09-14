#include "singleElement.h"
#include "ui_singleElement.h"
#include <QSet>

using namespace QP;

singleElement::singleElement(element e, QWidget *parent ) :
    QWidget(parent),
    m_initData(e),
    ui(new Ui::singleElement)
{
    ui->setupUi(this);
    ui->title->setText(m_initData.title);

}

singleElement::~singleElement()
{
    delete ui;
}

void singleElement::parseElementSetting()
{
    m_placeholderName.clear();
    QSet<QString> nameSet;
    nameSet.clear();

    QString originStr = m_initData.contentBase;
    for(int placeHolderStart = 0;
        -1 != (placeHolderStart = originStr.indexOf("_oOS_", placeHolderStart));)
    {
        int placeHolderStartCounter = originStr.indexOf("_EOo_", placeHolderStart);
        if(-1 == placeHolderStartCounter)
            continue;
        QString PlaceHolder = originStr.mid(placeHolderStart, placeHolderStartCounter - placeHolderStart);
        QStringList whatParped = PlaceHolder.split("_",QString::SkipEmptyParts);
        if(whatParped.size() < 2)
            continue;
        QString itemName = whatParped[1];
        if(!nameSet.contains(itemName))
        {
            m_placeholderName.append(itemName);
            nameSet.insert(itemName);
        }

    }
}

