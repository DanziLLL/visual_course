#ifndef VIEWTABLE_H
#define VIEWTABLE_H

#include <QDialog>
#include <QSqlTableModel>
#include <QTableView>
#include <QDebug>
#include <QtSql>
#include <QMouseEvent>
#include <QShortcut>
#include <QImage>
#include <QLabel>

namespace Ui {
class viewTable;
}

class viewTable : public QDialog
{
    Q_OBJECT

public:
    QString group, user;
    QSqlDatabase db = QSqlDatabase::database("db_conn");
    QSqlTableModel *sql_view;
    QTableView *t;
    QLabel *img;
    explicit viewTable(QWidget *parent = 0, QString gr = "", QString usr = "");
    void rentedMovies();
    ~viewTable();

private slots:
    void editActivated();

    void onDoubleClick(const QModelIndex &idx);

    void on_btn_Search_clicked();

    void on_btn_Reset_clicked();

    void on_btn_adminLogToday_clicked();

    void on_btn_adminLogOverdue_clicked();

    void on_btn_showFavorites_clicked();

private:
    Ui::viewTable *ui;

protected:
   virtual void keyPressEvent(QKeyEvent *event);
};

#endif // VIEWTABLE_H
