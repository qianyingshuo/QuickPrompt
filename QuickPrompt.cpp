#include "QuickPrompt.h"
#include "ui_QuickPrompt.h"

namespace QP {


QuickPrompt::QuickPrompt(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QuickPrompt)
{
    ui->setupUi(this);
}

QuickPrompt::~QuickPrompt()
{
    delete ui;
}

}
