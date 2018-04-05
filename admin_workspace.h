#ifndef ADMIN_WORKSPACE_H
#define ADMIN_WORKSPACE_H

#include <QDialog>
#include <QtSql>
#include <addmovie.h>
#include <viewtable.h>
#include <adduser.h>

namespace Ui {
class Admin_workspace;
}

class Admin_workspace : public QDialog
{
    Q_OBJECT

public:
    AddMovie *a;
    addUser *add;
    QSqlDatabase db = QSqlDatabase::database("db_conn");
    explicit Admin_workspace(QWidget *parent = 0);
    ~Admin_workspace();

private slots:
    void on_btn_AddMovie_clicked();

    void on_btn_ChangeAdPicture_clicked();

    void on_btn_ViewMovieDb_clicked();

    void on_btn_addUser_clicked();

private:
    Ui::Admin_workspace *ui;
};

#endif // ADMIN_WORKSPACE_H
