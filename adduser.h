#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QtSql>
#include <QString>
#include <QDebug>

namespace Ui {
class addUser;
}

class addUser : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase db = QSqlDatabase::database("db_conn");
    explicit addUser(QWidget *parent = 0);
    ~addUser();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addUser *ui;
};

#endif // ADDUSER_H
