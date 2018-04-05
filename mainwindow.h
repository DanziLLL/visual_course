#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QCryptographicHash>
#include <admin_workspace.h>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL", "db_conn");
    ~MainWindow();

private slots:
    void on_btn_go_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
