#ifndef FILMVIEW_H
#define FILMVIEW_H

#include <QDialog>
#include "film.h"

namespace Ui {
class FilmView;
}

class FilmView : public QDialog
{
    Q_OBJECT

public:
    explicit FilmView(Film* film, QWidget *parent = nullptr);
    ~FilmView();

private:
    Ui::FilmView *ui;
};

#endif // FILMVIEW_H
