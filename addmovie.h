#ifndef ADDMOVIE_H
#define ADDMOVIE_H

#include <QDialog>
#include <QtWebKitWidgets>

namespace Ui {
class AddMovie;
}

class AddMovie : public QDialog
{
    Q_OBJECT

public:
    QWebView *v = new QWebView();
    explicit AddMovie(QWidget *parent = 0);
    ~AddMovie();

private:
    Ui::AddMovie *ui;
};

#endif // ADDMOVIE_H
//#//#
