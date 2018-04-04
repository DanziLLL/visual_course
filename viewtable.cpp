#include "viewtable.h"
#include "ui_viewtable.h"

viewTable::viewTable(QWidget *parent, QString gr) :
    QDialog(parent),
    ui(new Ui::viewTable)
{
    group = gr;
    sql_view = new QSqlTableModel(this, db);
    sql_view->setTable("moviedb");
    qDebug() << sql_view->select();
    ui->tableView->setModel(sql_view);
    ui->setupUi(this);
}

viewTable::~viewTable()
{
    delete ui;
}
