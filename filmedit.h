#ifndef FILMEDIT_H
#define FILMEDIT_H

#include <QDialog>
#include "film.h"
#include "SaveAndLoad.h"

namespace Ui {
class FilmEdit;
}

class FilmEdit : public QDialog
{
    Q_OBJECT

public:
    explicit FilmEdit(Film* film, QWidget *parent = nullptr);
    ~FilmEdit();

private slots:
    void on_saveButton_clicked();

    void on_resetButton_clicked();

private:
    Film* film;
    SaveAndLoad& sal = SaveAndLoad::init();

    Ui::FilmEdit *ui;
};

#endif // FILMEDIT_H
