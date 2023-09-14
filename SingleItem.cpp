#include "SingleItem.h"
#include "ui_SingleItem.h"

namespace QP {


SingleItem::SingleItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleItem)
{
    ui->setupUi(this);
}

SingleItem::~SingleItem()
{
    delete ui;
}

void SingleItem::setName(QString name)
{
     ui->item->setPlaceholderText(name);
}

QString SingleItem::getItemContent()
{
    QString content = ui->item->text();
    content = content.simplified();
    content.remove("\r\n");
    content.remove("\n");
    return content;
}
}
