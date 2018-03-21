#include "admin_workspace.h"
#include "ui_admin_workspace.h"

Admin_workspace::Admin_workspace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_workspace)
{
    ui->setupUi(this);
}

Admin_workspace::~Admin_workspace()
{
    delete ui;
}

void Admin_workspace::on_btn_AddMovie_clicked()
{
    a = new AddMovie();
    a->show();
}
