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
    if(name.endsWith(":"))
        ui->name->setText(name+":");
    else
        ui->name->setText(name);
}

QString SingleItem::getItemContent()
{
    QString content = ui->item->text();
    content.simplified();
    content.remove("\r\n");
    return content;
}
}
