#include "adduser.h"
#include "ui_adduser.h"

addUser::addUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addUser)
{
    ui->setupUi(this);
    ui->groupCombo->addItem("users");
    ui->groupCombo->addItem("admins");
    ui->groupCombo->setCurrentIndex(0);
}

addUser::~addUser()
{
    delete ui;
}

void addUser::on_buttonBox_accepted()
{
    if (ui->userName->text() == "") {
        QMessageBox::critical(this, "Error", "Не задано имя пользователя!");
        this->open();
        return;
    }
    if (ui->password->text() != ui->cPassword->text()) {
        QMessageBox::critical(this, "Error", "Пароли не совпадают!");
        this->open();
        return;
    }
    QSqlQuery q(db);
    QString pass = QCryptographicHash::hash(ui->password->text().toUtf8(), QCryptographicHash::Md5).toHex();
    QString query = QString("INSERT INTO `users` (`login`, `pass_hash`, `group`) VALUES ('%1', '%2', '%3');")
            .arg(ui->userName->text()).arg(pass).arg(ui->groupCombo->currentText());
    qDebug() << query;
    q.exec(query);
    return;
}
