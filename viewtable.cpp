#include "viewtable.h"
#include "ui_viewtable.h"

viewTable::viewTable(QWidget *parent, QString gr) :
    QDialog(parent),
    ui(new Ui::viewTable)
{
    ui->setupUi(this);
    group = gr;
    sql_view = new QSqlTableModel(this, db);
    sql_view->setTable("moviedb");
    sql_view->select();
    t = new QTableView(this);
    t->setGeometry(20, 20, 561, 561);
    t->setModel(sql_view);
    sql_view->setEditStrategy(QSqlTableModel::OnFieldChange);
    if (group == "admins") {
        QShortcut *s = new QShortcut(QKeySequence("Ctrl+E"), this);
        connect(s, SIGNAL(activated()), SLOT(editActivated()));
        t->setEditTriggers(QTableView::EditKeyPressed);

    }
    else {
        ui->btn_adminLogToday->hide();
        t->setEditTriggers(QTableView::NoEditTriggers);
    }
    QStringList l;
    for (int i = 0; i < sql_view->columnCount(); i++) {
        l.append(sql_view->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString());
    }

    connect(t, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(onDoubleClick(const QModelIndex &)));
    ui->searchFilters->addItems(l);
}

viewTable::~viewTable()
{
    delete ui;
}

void viewTable::editActivated() {
    t->edit(t->currentIndex());
}

void viewTable::onDoubleClick(const QModelIndex &idx) {
    t->selectionModel()->setCurrentIndex(t->model()->index(idx.row(), 1), QItemSelectionModel::Select);
    QSqlQuery q(db);
    q.exec(QString("INSERT INTO `rent_log` (`name`, `date_start`, `date_end`) VALUES "
                   "('%1', CURDATE(), CURDATE() + INTERVAL 3 DAY)").arg( t->currentIndex().data().toString()));
}

void viewTable::on_btn_Search_clicked()
{
    sql_view->setFilter(QString("`%1` LIKE \"%%%2%%\"").arg(ui->searchFilters->currentText()).arg(ui->searchQuery->text()));
}

void viewTable::on_btn_Reset_clicked()
{
    sql_view->setTable("moviedb");
    sql_view->setFilter("");
}

void viewTable::on_btn_adminLogToday_clicked()
{
    sql_view->setTable("rent_log");
    sql_view->select();
    sql_view->setFilter("`date_start` = CURDATE()");
}
