#ifndef DATATYPEDEFINE_H
#define DATATYPEDEFINE_H

#include <QString>
#include <QStringList>

#define BINGAI_NET_ADDRESS_QUESTION  "https://www.bing.com/search?form=MY0291&OCID=MY0291&q=_oO_Question_Oo_&showconv=1"
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

struct allAiParseAddress
{
    QString newBing = "https://www.bing.com/search?form=MY0291&OCID=MY0291&q=%1&showconv=1";
};

}
#endif // DATATYPEDEFINE_H
