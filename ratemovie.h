#ifndef RATEMOVIE_H
#define RATEMOVIE_H

#include <QDialog>

namespace Ui {
class rateMovie;
}

class rateMovie : public QDialog
{
    Q_OBJECT

public:
    explicit rateMovie(QWidget *parent = 0);
    ~rateMovie();

private:
    Ui::rateMovie *ui;
};

#endif // RATEMOVIE_H
