#ifndef DIRECTORVIEW_H
#define DIRECTORVIEW_H

#include <QDialog>
#include "director.h"

namespace Ui {
class DirectorView;
}

class DirectorView : public QDialog
{
    Q_OBJECT

public:
    explicit DirectorView(Director* director, QWidget *parent = nullptr);
    ~DirectorView();

private:
    Ui::DirectorView *ui;
};

#endif // DIRECTORVIEW_H
