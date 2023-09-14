#ifndef DATATYPEDEFINE_H
#define DATATYPEDEFINE_H

#include <QString>
#include <QStringList>
namespace QP{


class singleElement;
class QuickPrompt;



class element
{

    friend class singleElement;
    friend class QuickPrompt;
private:
    QString title = "noNameElement";
    QString contentBase;
};
}
#endif // DATATYPEDEFINE_H
