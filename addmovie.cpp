#include "addmovie.h"
#include "ui_addmovie.h"

AddMovie::AddMovie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovie)
{
    ui->setupUi(this);
}

AddMovie::~AddMovie()
{
    delete ui;
}

void AddMovie::on_btn_findMovie_clicked()
{
    QString s;
    s = QString("https://www.google.com/search?q=%1 +insite:imdb.com&btnI").arg(ui->movieName->text());
    QUrl q(s);
    this->v->show();
    qDebug() << q;
    v->load(q);
}

void AddMovie::on_btn_addMovie_clicked()
{
    QString name = "default", dir = "default", coun = "default",
            stud = "default", release = "00/00/00", synop = "default";
    if (ui->movieName->text() != "") {
        name = ui->movieName->text();
    }
    if (ui->director->text() != "") {
        dir = ui->director->text();
    }
    if (ui->country->text() != "") {
        coun = ui->country->text();
    }
    if (ui->studio->text() != "") {
        stud = ui->studio->text();
    }
    if (ui->releaseDate->text() != "") {
        release = ui->releaseDate->text();
    }
    if (ui->synopsis->toPlainText() != "") {
        synop = ui->synopsis->toPlainText();
    }
    QSqlQuery q(db);
    QString query;
    query = QString("INSERT INTO `moviedb` (name, director, country, studio, release_date, synopsis) "
                    "VALUES ('%1', '%2', '%3', '%4', '%5', '%6');").arg(name).arg(dir)
            .arg(coun).arg(stud).arg(release).arg(synop);
    q.exec(query);
}
