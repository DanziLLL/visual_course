#ifndef VIEWTABLE_H
#define VIEWTABLE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QTableView>
#include <QDebug>

namespace Ui {
class viewTable;
}

class viewTable : public QDialog
{
    Q_OBJECT

public:
    QString group;
    QSqlDatabase db = QSqlDatabase::database("db_conn");
    QSqlTableModel *sql_view;
    explicit viewTable(QWidget *parent = 0, QString gr = "");
    ~viewTable();

private:
    Ui::viewTable *ui;
};

#endif // VIEWTABLE_H
