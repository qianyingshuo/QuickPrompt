#ifndef SINGLEELEMENT_H
#define SINGLEELEMENT_H

#include <QFrame>
#include "DataTypeDefine.h"
#include <QList>
#include <QPair>

namespace Ui {
class singleElement;
}

namespace QP{
class singleElement : public QFrame
{
    Q_OBJECT

public:
    explicit singleElement(element e, QWidget *parent = nullptr);
    ~singleElement();

    bool eventFilter(QObject *obj, QEvent *event);

    public slots:
    void on_pushButton_clicked();

private:
     void parseElementSetting();
     QString generateResult();
private:
    Ui::singleElement *ui;
    element m_initData;
    QList<QString> m_placeholderName;
};
}
#endif // SINGLEELEMENT_H
