#include "admin_workspace.h"
#include "ui_admin_workspace.h"

Admin_workspace::Admin_workspace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_workspace)
{
    ui->setupUi(this);
}

Admin_workspace::~Admin_workspace()
{
    delete ui;
}

void Admin_workspace::on_btn_AddMovie_clicked()
{
    a = new AddMovie();
    a->show();
}

void Admin_workspace::on_btn_ChangeAdPicture_clicked()
{
    QString pic_path = QFileDialog::getOpenFileName(this, "Select image file", ".", "Image files: (*.jpg *.png *.bmp);;All files (*.*)");
    QFile f(pic_path);
    f.open(QIODevice::ReadOnly);
    QByteArray pic_blob(f.readAll());
    QString mysql_blob = pic_blob.toBase64();
    QSqlQuery q(db);
    q.exec(QString("REPLACE INTO `adpic` (`id`, `pic`, `filename`) VALUES ('1', '%1', '%2');").arg(mysql_blob).arg(pic_path.split('/').last()));
}

void Admin_workspace::on_btn_ViewMovieDb_clicked()
{
    viewTable *t = new viewTable(this, "admins");
    t->show();
    this->hide();
}
