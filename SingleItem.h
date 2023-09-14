#ifndef SINGLEITEM_H
#define SINGLEITEM_H

#include <QWidget>

namespace Ui {
class SingleItem;
}

namespace QP {



class SingleItem : public QWidget
{
    Q_OBJECT

public:
    explicit SingleItem(QWidget *parent = nullptr);
    ~SingleItem();

    void setName(QString name);
    QString getItemContent();

private:
    Ui::SingleItem *ui;
};
}
#endif // SINGLEITEM_H
