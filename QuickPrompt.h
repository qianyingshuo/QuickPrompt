#ifndef QUICKPROMPT_H
#define QUICKPROMPT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class QuickPrompt; }
QT_END_NAMESPACE

class QuickPrompt : public QMainWindow
{
    Q_OBJECT

public:
    QuickPrompt(QWidget *parent = nullptr);
    ~QuickPrompt();

private:
    Ui::QuickPrompt *ui;
};
#endif // QUICKPROMPT_H
