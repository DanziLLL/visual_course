#ifndef ADMIN_WORKSPACE_H
#define ADMIN_WORKSPACE_H

#include <QDialog>
#include <addmovie.h>

namespace Ui {
class Admin_workspace;
}

class Admin_workspace : public QDialog
{
    Q_OBJECT

public:
    AddMovie *a;
    explicit Admin_workspace(QWidget *parent = 0);
    ~Admin_workspace();

private slots:
    void on_btn_AddMovie_clicked();

private:
    Ui::Admin_workspace *ui;
};

#endif // ADMIN_WORKSPACE_H
