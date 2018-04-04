#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    db.setHostName("localhost");
    db.setDatabaseName("rentamovie");
    db.setUserName("rentamovie");
    db.setPassword("interstellar");
    db.open();
    ui->setupUi(this);
    ui->login->setFocus();
    ui->btn_go->setDefault(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_go_clicked()
{
    QString h = QCryptographicHash::hash(ui->password->text().toUtf8(), QCryptographicHash::Md5).toHex(); //generating md5 hash from password
    QSqlQuery q(db);
    if (!q.exec(QString("SELECT `pass_hash`, `group` FROM users WHERE login='%1'").arg(ui->login->text()))) {
        QMessageBox::critical(this, "Error", "Пользователь не найден");
    }; //looking up for hash in database
    q.next();
    if (q.value(0).toString() == h) {
        if (q.value(1).toString() == "admins") {
            Admin_workspace *a = new Admin_workspace();
            this->hide();
            a->show();
        }
        else if (q.value(1).toString() == "users") {
            User_workspace *u = new User_workspace();
            this->hide();
            u->show();
        }
        else {
            QMessageBox::critical(this, "Error", "Не установлена группа пользователя");
        }
    }
    else {
        qDebug() << "PASS ERR";
    }
}
