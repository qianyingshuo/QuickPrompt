#ifndef QUICKPROMPT_H
#define QUICKPROMPT_H

#include <QMainWindow>
#include <QSettings>

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

public slots:
    void setNewBrowserPath();
private:
    void parserAppSetting();
    void creatViewByFile();

private:
    Ui::QuickPrompt *ui;
    bool isRight = false;
    QSettings *m_appSet{nullptr};
};

}
#endif // QUICKPROMPT_H
