#include "singleElement.h"
#include "ui_singleElement.h"
#include <QSet>
#include "SingleItem.h"
#include <QClipboard>

using namespace QP;

singleElement::singleElement(element e, QWidget *parent ) :
    QFrame(parent),
    m_initData(e),
    ui(new Ui::singleElement)
{
    ui->setupUi(this);
    ui->title->setText(m_initData.title);
    parseElementSetting();
    for(auto name:m_placeholderName)
    {
        SingleItem* item = new SingleItem(this);
        item->setName(name);
        item->setObjectName(name);
        ui->itemsLayout->addWidget(item);
    }
    ui->pushButton->setAttribute(Qt::WA_Hover, true);
    ui->pushButton->installEventFilter(this);
    //connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(on_pushButton_clicked()));
    
}

singleElement::~singleElement()
{
    delete ui;
}

bool singleElement::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->pushButton) {
        if (event->type() == QEvent::Enter) {
            static_cast<QPushButton*>(obj)->setToolTip(generateResult());
            return true;
        } else {
            return false;
        }
    } else {
        // pass the event on to the parent class
        return QWidget::eventFilter(obj, event);
    }
}

void singleElement::on_pushButton_clicked()
{
    QClipboard* clip = QApplication::clipboard();
    clip->setText(generateResult());
}

void singleElement::parseElementSetting()
{
    m_placeholderName.clear();
    QSet<QString> nameSet;
    nameSet.clear();

    QString originStr = m_initData.contentBase;
    for(int placeHolderStart = originStr.indexOf("_oOS_", 0);
        -1!= placeHolderStart;
        placeHolderStart = originStr.indexOf("_oOS_", placeHolderStart + 1))
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

QString singleElement::generateResult()
{
    QString contents = m_initData.contentBase;
    for(auto name : m_placeholderName)
    {
        contents.replace(QString("_oOS_%1_EOo_").arg(name),
                         findChild<SingleItem*>(name)->getItemContent());
    }
    return contents;
}

