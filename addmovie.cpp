#include "addmovie.h"
#include "ui_addmovie.h"

AddMovie::AddMovie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovie)
{
    v->setParent(this);
    v->setGeometry(512, 30, 500, 600);
    v->show();
    QUrl q("http://ngs.ru");
    v->load(q);
    ui->setupUi(this);
}

AddMovie::~AddMovie()
{
    delete ui;
}
