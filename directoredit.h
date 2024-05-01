#ifndef DIRECTOREDIT_H
#define DIRECTOREDIT_H

#include <QDialog>
#include "saveandload.h"
#include "director.h"

namespace Ui {
class DirectorEdit;
}

class DirectorEdit : public QDialog
{
    Q_OBJECT

public:
    explicit DirectorEdit(Director* director, QWidget *parent = nullptr);
    ~DirectorEdit();

private slots:
    void on_saveButton_clicked();

    void on_resetButton_clicked();

private:
    Director* director;
    SaveAndLoad& sal = SaveAndLoad::init();

    Ui::DirectorEdit *ui;
};

#endif // DIRECTOREDIT_H
