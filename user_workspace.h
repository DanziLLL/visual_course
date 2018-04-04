#ifndef USER_WORKSPACE_H
#define USER_WORKSPACE_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class User_workspace;
}

class User_workspace : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db = QSqlDatabase::database("db_conn");
    explicit User_workspace(QWidget *parent = 0);
    ~User_workspace();

private:
    Ui::User_workspace *ui;
};

#endif // USER_WORKSPACE_H
