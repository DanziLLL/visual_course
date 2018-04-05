#include "viewtable.h"
#include "ui_viewtable.h"

viewTable::viewTable(QWidget *parent, QString gr, QString usr) :
    QDialog(parent),
    ui(new Ui::viewTable)
{
    ui->setupUi(this);
    group = gr;
    user = usr;
    sql_view = new QSqlTableModel(this, db);
    sql_view->setTable("moviedb");
    sql_view->select();
    t = new QTableView(this);
    t->setModel(sql_view);
    if (group == "users" ){
        t->setGeometry(20, 20, 561, 411);
        QSqlQuery q(db);
        q.exec(QString("SELECT * FROM `adpic`;"));
        q.next();
        QPixmap adimg;
        adimg.loadFromData(QByteArray::fromBase64(q.value(0).toByteArray()));
        img = new QLabel(this);
        img->setPixmap(adimg);
        img->setGeometry(20, 461, 400, 100);
        img->show();
        ui->btn_adminLogOverdue->hide();
        ui->btn_adminLogToday->hide();
        rentedMovies();
    }
    else {
        t->setGeometry(20, 20, 561, 561);
    }
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

void viewTable::rentedMovies() {
    QSqlQuery q(db);
    sql_view->select();
    sql_view->setFilter("");
    q.exec("SELECT DISTINCT `name` FROM `rent_log` WHERE `date_return` IS NULL;");
    QStringList rented;
    while (q.next()) {
        rented.append(q.value(0).toString());
    }
    for (int i = 0; i < rented.length(); i++) {
        for (int j = 0; j < sql_view->rowCount(); j++) {
            t->selectionModel()->setCurrentIndex(t->model()->index(j, 1), QItemSelectionModel::Select);
            if (t->currentIndex().data().toString() == rented.at(i)) {
                t->hideRow(j);
            }
        }
    }
    t->clearSelection();
    t->scrollToTop();
}

viewTable::~viewTable()
{
    delete ui;
}

void viewTable::editActivated() {
    t->edit(t->currentIndex());
}

void viewTable::onDoubleClick(const QModelIndex &idx) {
    if ((group == "users") && (sql_view->tableName() == "moviedb")){
        t->selectionModel()->setCurrentIndex(t->model()->index(idx.row(), 1), QItemSelectionModel::Select);
        QSqlQuery q(db);
        qDebug() << q.exec(QString("INSERT INTO `rent_log` (`name`, `date_start`, `date_end`, `user`) VALUES "
                       "('%1', CURDATE(), CURDATE() + INTERVAL 3 DAY, '%2')").arg( t->currentIndex().data().toString()).arg(user));
    }
    if ((group == "admins") && (sql_view->tableName() == "rent_log")) {
        QSqlQuery q(db);
        t->selectionModel()->setCurrentIndex(t->model()->index(idx.row(), 0), QItemSelectionModel::Select);
        q.exec(QString("UPDATE `rent_log` SET `date_return` = CURDATE() WHERE `id` = '%1';").arg(t->currentIndex().data().toString()));
    }
}

void viewTable::on_btn_Search_clicked()
{
    sql_view->setFilter(QString("`%1` LIKE \"%%%2%%\"").arg(ui->searchFilters->currentText()).arg(ui->searchQuery->text()));
}

void viewTable::on_btn_Reset_clicked()
{
    if (group == "users") {
        rentedMovies();
        return;
    }
    sql_view->setTable("moviedb");
    sql_view->select();
    sql_view->setFilter("");
}

void viewTable::on_btn_adminLogToday_clicked()
{
    sql_view->setTable("rent_log");
    sql_view->select();
    sql_view->setFilter("(`date_start` = CURDATE()) AND (`date_start` <> `date_end`)");
}

void viewTable::on_btn_adminLogOverdue_clicked()
{
    sql_view->setTable("rent_log");
    sql_view->select();
    sql_view->setFilter("(`date_end` < `date_return`) OR (`date_end` < CURDATE() AND `date_return` = NULL)");
}

void viewTable::keyPressEvent(QKeyEvent *event) {
    int key = event->key();
    qDebug() << key;
}
