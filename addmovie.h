#ifndef ADDMOVIE_H
#define ADDMOVIE_H

#include <QDialog>
#include <QtSql>
#include <QtWebKitWidgets>
#include <QDebug>

namespace Ui {
class AddMovie;
}

class AddMovie : public QDialog
{
    Q_OBJECT

public:
    QWebView *v = new QWebView();
    QSqlDatabase db = QSqlDatabase::database("db_conn");
    explicit AddMovie(QWidget *parent = 0);
    ~AddMovie();

private slots:
    void on_btn_findMovie_clicked();

    void on_btn_addMovie_clicked();

private:
    Ui::AddMovie *ui;
};

#endif // ADDMOVIE_H
//#//#
