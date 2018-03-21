#ifndef WORKFIELD_H
#define WORKFIELD_H

#include <QDialog>

namespace Ui {
class workfield;
}

class workfield : public QDialog
{
    Q_OBJECT

public:
    explicit workfield(QWidget *parent = 0);
    ~workfield();

private:
    Ui::workfield *ui;
};

#endif // WORKFIELD_H
