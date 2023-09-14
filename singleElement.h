#ifndef SINGLEELEMENT_H
#define SINGLEELEMENT_H

#include <QWidget>
#include "DataTypeDefine.h"
#include <QList>
#include <QPair>

namespace Ui {
class singleElement;
}

namespace QP{
class singleElement : public QWidget
{
    Q_OBJECT

public:
    explicit singleElement(element e, QWidget *parent = nullptr);
    ~singleElement();

private:
     void parseElementSetting();
private:
    Ui::singleElement *ui;
    element m_initData;
    QList<QString> m_placeholderName;
};
}
#endif // SINGLEELEMENT_H
