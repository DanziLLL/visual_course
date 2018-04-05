#include "ratemovie.h"
#include "ui_ratemovie.h"

rateMovie::rateMovie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rateMovie)
{
    ui->setupUi(this);
}

rateMovie::~rateMovie()
{
    delete ui;
}

void rateMovie::on_buttonBox_accepted()
{
    rating = ui->spinBox->value();
}

int rateMovie::getValue() {
    return rating;
}
