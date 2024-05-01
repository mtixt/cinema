#ifndef HALLEDIT_H
#define HALLEDIT_H

#include <QDialog>
#include "hall.h"
#include "saveandload.h"

namespace Ui {
class HallEdit;
}

class HallEdit : public QDialog
{
    Q_OBJECT

public:
    explicit HallEdit(Hall* hall, QWidget *parent = nullptr);
    ~HallEdit();

private slots:
    void on_saveButton_clicked();

    void on_resetButton_clicked();

private:
    Hall* hall;
    SaveAndLoad& sal = SaveAndLoad::init();

    Ui::HallEdit *ui;
};

#endif // HALLEDIT_H
