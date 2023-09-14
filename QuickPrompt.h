#ifndef QUICKPROMPT_H
#define QUICKPROMPT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QuickPrompt; }
QT_END_NAMESPACE

namespace QP {

class QuickPrompt : public QMainWindow
{
    Q_OBJECT

public:
    QuickPrompt(QWidget *parent = nullptr);
    ~QuickPrompt();

    void creatViewByFile();

private:
    Ui::QuickPrompt *ui;
    bool isRight = false;
};

}
#endif // QUICKPROMPT_H
