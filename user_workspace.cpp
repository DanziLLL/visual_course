#include "user_workspace.h"
#include "ui_user_workspace.h"

User_workspace::User_workspace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::User_workspace)
{
    ui->setupUi(this);
}

User_workspace::~User_workspace()
{
    delete ui;
}
