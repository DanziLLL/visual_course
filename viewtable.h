#ifndef VIEWTABLE_H
#define VIEWTABLE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QTableView>
#include <QDebug>
#include <QtSql>
#include <QMouseEvent>
#include <QShortcut>

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
    QTableView *t;
    explicit viewTable(QWidget *parent = 0, QString gr = "");
    ~viewTable();

private slots:
    void editActivated();

    void onDoubleClick(const QModelIndex &idx);

    void on_btn_Search_clicked();

    void on_btn_Reset_clicked();

    void on_btn_adminLogToday_clicked();

private:
    Ui::viewTable *ui;
};

#endif // VIEWTABLE_H
