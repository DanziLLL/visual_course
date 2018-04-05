#ifndef RATEMOVIE_H
#define RATEMOVIE_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class rateMovie;
}

class rateMovie : public QDialog
{
    Q_OBJECT

public:
    int rating = 0;
    int getValue();
    QSqlDatabase db = QSqlDatabase::database("db_conn");
    explicit rateMovie(QWidget *parent = 0);
    ~rateMovie();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::rateMovie *ui;
};

#endif // RATEMOVIE_H
